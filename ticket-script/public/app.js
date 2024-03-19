document.getElementById('start').addEventListener('click', async () => {
    console.log('Button clicked');
    const formData = new FormData(document.getElementById('userInputForm'));
    const formDataSerialized = Object.fromEntries(formData);
    const fetchData = {
        method: 'POST',
        headers: {
            'Content-Type': 'application/json',
        },
        body: JSON.stringify(formDataSerialized),
    };
    
    fetch('/start', fetchData)
        .then(response => response.text())
        .then(data => alert(data))
        .catch(error => console.error('Error:', error));
});