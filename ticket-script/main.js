const express = require('express');
const bodyParser = require('body-parser');
const puppeteer = require('puppeteer-extra');
const StealthPlugin = require('puppeteer-extra-plugin-stealth');
const app = express();
const port = 3000;

puppeteer.use(StealthPlugin());

// Serve static files from the 'public' directory
app.use(express.static('public'));

app.use(bodyParser.json());

// Endpoint to handle scraping
app.post('/start', async (req, res) => {
    
    const { ticketString, firstNameString, lastNameString, phoneString, emailString, countryCodeString, genderString,
            birthDateString, cardNumberString, cardMonthExpString, cardYearExpString, cvvString } = req.body;
    
    //const browser = await puppeteer.launch({ headless: false });
    const browser = await puppeteer.launch({ headless: false }); //"new"

    // assume backend is already loaded
    let backendError = false;

    const page = await browser.newPage();
    page.setDefaultNavigationTimeout(100000);
    await page.setUserAgent('Mozilla/5.0 (Windows NT 10.0; Win64; x64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/91.0.4472.124 Safari/537.36')
    //CHANGE AGENT TO BROWSER VERSION AND MORE IMPORTANTLY BROWSER TO OPEN
    await page.goto('example-url');

    await page.waitForSelector('#pdcc-modal-accept', { visible: true });
    await page.evaluate(() => {
        document.querySelector('#pdcc-modal-accept').click();
      });

    let carted = false;
    const retryDelayMs = 2000;

    while (!carted) 
    {

        await page.waitForSelector('#SaleNoLoginModal')
        const popUp = await page.$('#SaleNoLoginModal');

        try {
            const ticketButton = await page.$(`[data-service-id="${ticketString}"]`); 
            await ticketButton.evaluate(b => b.click());
            
        } catch {
            backendError = true;
        }

        await page.waitForTimeout(500);

        let isAriaHidden = await page.evaluate(el => el.getAttribute('aria-hidden'), popUp);

        if (isAriaHidden == "false") 
        {
            console.log('Ticket Carted!');
            carted = true;
            backendError = false;
        } 
        else if (backendError == true)
        {
            console.log("Backend element unloaded, refreshing the page...");
            await page.waitForTimeout(retryDelayMs);
            await page.reload({ waitUntil: ["networkidle0", "domcontentloaded"] });
        }
        else if (isAriaHidden == "true") 
        {
            console.log(`Attempt failed, refreshing the page...`);
            await page.waitForTimeout(retryDelayMs);
            await page.reload({ waitUntil: ["networkidle0", "domcontentloaded"] });
        }
    }  

    await page.waitForTimeout(350);
    const delay = 2;

    await page.waitForSelector('#sl_firstname', {visible: true});
    const firstName = await page.$('#sl_firstname');
    await firstName.type(firstNameString, {delay: delay});

    await page.waitForSelector('#sl_lastname', {visible: true});
    const lastName = await page.$('#sl_lastname');
    await lastName.type(lastNameString, {delay: delay});

    await page.waitForSelector('#sl_tlfn1', {visible: true});
    const phone = await page.$('#sl_tlfn1');
    await phone.type(phoneString, {delay: delay});

    await page.waitForSelector('#sl_email', {visible: true});
    const email = await page.$('#sl_email');
    await email.evaluate(b => b.click());
    await email.type(emailString, {delay: delay});

    await page.waitForSelector('#sl_remail', {visible: true});
    const remail = await page.$('#sl_remail');
    await remail.evaluate(b => b.click());
    await remail.type(emailString, {delay: delay});

    await page.waitForSelector('.iti__selected-flag', {visible: true});
    await page.click('.iti__selected-flag');

    //DONT FORGET AREACODE STRING HERE!!!!!!!!!!!!!!!!!!!!!!!!
    await page.waitForSelector('#iti-1__item-ad', { visible: true });
    await page.click(countryCodeString);

    await page.waitForSelector('#sl_sex', { visible: true });
    await page.select('#sl_sex', genderString); 

    await page.evaluate((date) => {
        var inputElement = document.querySelector('#sl_birthdate');
        if (inputElement) {
            inputElement.value = date;
    
            // Create and dispatch the 'change' event only if the element exists
            var event = new Event('change', { bubbles: true, cancelable: true });
            inputElement.dispatchEvent(event); // Force event to happen to update the frontend
        } else {
            console.error('Input element not found');
        }
    }, birthDateString);

    await page.waitForSelector('#sl_send', {visible: true});
    const nextButton = await page.$('#sl_send');
    await nextButton.evaluate(b => b.click());

    await page.waitForSelector('#TpvBtn', {visible: true});
    const cardButton = await page.$('#TpvBtn');
    await cardButton.evaluate(b => b.click());

    await page.waitForTimeout(350);

    ////////////////////////PAYMENT/////////////////////////

    await page.waitForSelector('#inputCard');
    const card = await page.$('#inputCard');
    await card.type(cardNumberString);

    await page.waitForSelector('#cad1');
    const month = await page.$('#cad1');
    await month.type(cardMonthExpString);

    await page.waitForSelector('#cad2');
    const year = await page.$('#cad2');
    await year.type(cardYearExpString);

    await page.waitForSelector('#codseg');
    const cvv = await page.$('#codseg');
    await cvv.type(cvvString);

    await page.waitForTimeout(250);
    
    /*
    await page.waitForSelector('#divImgAceptar', {visible: true});
    const buyButton = await page.$('#divImgAceptar');
    await buyButton.evaluate(b => b.click());
    */
});

// Start the server
app.listen(port, () => {
    console.log(`Server listening at http://localhost:${port}`);
});