document.getElementById('recordForm').addEventListener('submit', (event) => {
    const textInput = document.getElementById('birthday').value;
    if (!validDate(textInput)) {
        document.getElementById("errorMessage").style.display = 'block';
        event.preventDefault();
    } else {
        document.getElementById("errorMessage").style.display = 'none';
    }
});
    

function validDate(date) {
    var months = ["January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December"];
    var components = date.split(" ");
    if (components.length == 3 && months.includes(components[0])) {
        var dateObjIn = "" + (months.indexOf(components[0])+1) + "/" + components[1].replace(/,/, '/') + components[2];
        return !isNaN(new Date(dateObjIn));
    }
    return false;
}
