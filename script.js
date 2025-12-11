const display = document.getElementById("display");

function appendValue(value) {
    if (value === "C") {
        display.value = "";
    } 
    else if (value === "DEL") {
        display.value = display.value.slice(0, -1);
    } 
    else if (value === "=") {
        try {
            display.value = eval(display.value);
        } catch {
            display.value = "Error";
        }
    } 
    else {
        display.value += value;
    }
}

document.querySelectorAll(".btn").forEach(button => {
    button.addEventListener("click", () => {
        appendValue(button.dataset.value);
    });
});

// Keyboard support
document.addEventListener("keydown", (e) => {
    if (/[0-9+\-*/.]/.test(e.key)) {
        appendValue(e.key);
    } else if (e.key === "Enter") {
        appendValue("=");
    } else if (e.key === "Backspace") {
        appendValue("DEL");
    } else if (e.key === "Escape") {
        appendValue("C");
    }
});
