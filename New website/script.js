


 /* nav-title and into-text2 animation when first loading page */
 window.addEventListener("DOMContentLoaded", () => {
    const elements = document.querySelectorAll(".nav-title, .intro-text2");
  
    elements.forEach((el) => {
      el.classList.add("animate");
  
      // After animation ends, fully reset to enable first hover
      setTimeout(() => {
        el.classList.remove("animate");
  
        // Forcefully remove any inline transform left by animation
        el.querySelectorAll("span").forEach((span) => {
          span.style.removeProperty("transform");
        });
      }, 1000); // matches your animation duration
    });
  });
  