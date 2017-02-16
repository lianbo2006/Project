var dark = "background-color: black; color: white;";
var day = "background-color: white; color: black;";

// var theme = {
//     dark:"background-color: black; color: white;",
//     day :"background-color: white; color: black;"
// };

var button = document.querySelector(".container");
var web = document.querySelector("body");

function lightSwitch() {
    if (web.style.cssText == dark) {
        web.style.cssText = day;
        alert("Day mode");
    } else {
        web.style.cssText = dark;
        alert("Night mode");
    }
}

button.onclick = lightSwitch
