
// Animate nav-title and intro-text2 on first load
window.addEventListener("DOMContentLoaded", () => {
  const elements = document.querySelectorAll(".animated-title, .nav-title, .intro-text2, .exp-title2");

  elements.forEach((el) => {
    el.classList.add("animate");

    // Reset after animation ends to allow hover animation to work smoothly
    setTimeout(() => {
      el.classList.remove("animate");

      // Clean up transform so hover scale works properly
      el.querySelectorAll("span").forEach((span) => {
        span.style.removeProperty("transform");
      });
    }, 1000); // Match your animation duration
  });
});

// Animate elements again when they enter viewport (like jumping to #about)
const observer = new IntersectionObserver(
  (entries) => {
    entries.forEach((entry) => {
      if (entry.isIntersecting) {
        entry.target.classList.add("animate");

        setTimeout(() => {
          entry.target.classList.remove("animate");

          entry.target.querySelectorAll("span").forEach((span) => {
            span.style.removeProperty("transform");
          });
        }, 1000);
      }
    });
  },
  { threshold: 0.5 }
);

// Observe all three elements
const animElements = document.querySelectorAll(".animated-title, .nav-title, .intro-text2, .exp-title2");
animElements.forEach((el) => {
  if (el) observer.observe(el);
});


//  /* nav-title and into-text2 animation when first loading page */
//  window.addEventListener("DOMContentLoaded", () => {
//     const elements = document.querySelectorAll(".nav-title, .intro-text2");
  
//     elements.forEach((el) => {
//       el.classList.add("animate");
  
//       // After animation ends, fully reset to enable first hover
//       setTimeout(() => {
//         el.classList.remove("animate");
  
//         // Forcefully remove any inline transform left by animation
//         el.querySelectorAll("span").forEach((span) => {
//           span.style.removeProperty("transform");
//         });
//       }, 1000); // matches your animation duration
//     });
//   });




//   // end of nav title and intro 



// // Animate animated-title when it enters the viewport
// const observer = new IntersectionObserver(
//   (entries) => {
//     entries.forEach((entry) => {
//       if (entry.isIntersecting) {
//         entry.target.classList.add("animate");

//         // Optional: Remove after 1s so hover still works smoothly
//         setTimeout(() => {
//           entry.target.classList.remove("animate");
//         }, 1000);
//       }
//     });
//   },
//   {
//     threshold: 0.5, // Trigger when 50% of the element is visible
//   }
// );

// const anim8title = document.querySelector(".animated-title");
// if (anim8title) {
//   observer.observe(anim8title);
// }
// const introText2 = document.querySelector(".nav-title");
// if (navtit) {
//   observer.observe(navtit);
// }

// const introText2 = document.querySelector(".intro-text2");
// if (introText2) {
//   observer.observe(introText2);
// }


  // about right side slideshow

  // let slideIndex = 0;
  // let slideInterval;
  // const slides = document.getElementsByClassName("slide");
  // const dots = document.getElementsByClassName("dot");
  // const slideshowContainer = document.getElementById("slideshow");
  
  // function showSlide(n) {
  //   for (let i = 0; i < slides.length; i++) {
  //     slides[i].style.display = "none";
  //   }
  
  //   for (let i = 0; i < dots.length; i++) {
  //     dots[i].classList.remove("active");
  //   }
  
  //   slides[n].style.display = "block";
  //   dots[n].classList.add("active");
  // }
  
  // function nextSlide() {
  //   slideIndex = (slideIndex + 1) % slides.length;
  //   showSlide(slideIndex);
  // }
  
  // function plusSlides(n) {
  //   slideIndex = (slideIndex + n + slides.length) % slides.length;
  //   showSlide(slideIndex);
  // }
  
  // function currentSlide(n) {
  //   slideIndex = n - 1;
  //   showSlide(slideIndex);
  // }
  
  // function startSlideShow() {
  //   slideInterval = setInterval(nextSlide, 4000);
  // }
  
  // function stopSlideShow() {
  //   clearInterval(slideInterval);
  // }
  
  // slideshowContainer.addEventListener("mouseenter", stopSlideShow);
  // slideshowContainer.addEventListener("mouseleave", startSlideShow);
  
  // // Initialize
  // showSlide(slideIndex);
  // startSlideShow();
  
// end of about right side slideshow
  