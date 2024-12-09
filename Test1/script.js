function toggleMenu() {

    // the two elements we target
    const menu = document.querySelector(".menu-links");
    const icon = document.querySelector(".hamburger-icon");
  
    // the action on those elements
    // basically, when we click hamburger, it selects the open functions
    // when we close hamburger, it selects the regular fns
    menu.classList.toggle("open")
    icon.classList.toggle("open")
  }




