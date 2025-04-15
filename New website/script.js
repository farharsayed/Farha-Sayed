


 /* nav-title and into-text2 animation when first loading page */
 window.addEventListener("DOMContentLoaded", () => {
    const elements = document.querySelectorAll(".nav-title, .intro-text2", ".animated-title");
  
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




  // end of nav title and intro 





  // about right side slideshow

  let slideIndex = 0;
  let slideInterval;
  const slides = document.getElementsByClassName("slide");
  const dots = document.getElementsByClassName("dot");
  const slideshowContainer = document.getElementById("slideshow");
  
  function showSlide(n) {
    for (let i = 0; i < slides.length; i++) {
      slides[i].style.display = "none";
    }
  
    for (let i = 0; i < dots.length; i++) {
      dots[i].classList.remove("active");
    }
  
    slides[n].style.display = "block";
    dots[n].classList.add("active");
  }
  
  function nextSlide() {
    slideIndex = (slideIndex + 1) % slides.length;
    showSlide(slideIndex);
  }
  
  function plusSlides(n) {
    slideIndex = (slideIndex + n + slides.length) % slides.length;
    showSlide(slideIndex);
  }
  
  function currentSlide(n) {
    slideIndex = n - 1;
    showSlide(slideIndex);
  }
  
  function startSlideShow() {
    slideInterval = setInterval(nextSlide, 4000);
  }
  
  function stopSlideShow() {
    clearInterval(slideInterval);
  }
  
  slideshowContainer.addEventListener("mouseenter", stopSlideShow);
  slideshowContainer.addEventListener("mouseleave", startSlideShow);
  
  // Initialize
  showSlide(slideIndex);
  startSlideShow();
  
// end of about right side slideshow
  