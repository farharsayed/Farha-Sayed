
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



// experience content
const experienceData = {
  2025: {
    title: "Gulf Business Machines - Infrastructure and Cyber Security Engineer",
    dates: "Nov 2024 - Present",
    description: `● Provided security solutions for endpoint, network, servers and cloud email security to customers including MBZ University of Artificial Intelligence, ICP, ADEK, ADJD etc.
    ● Collaborated with vendors to implement products such as Trend Micro XDR/EDR and ASM, FortiSASE, BeyondTrust PRA, Cisco User Protection Suite etc.
    ● Executed the major rollout on several projects, managing up to 15,000 endpoints and servers
    ● Followed entire project lifecycles from pre-sales to documentation and closure.`,
    
    image: "./assets/exp-pic1.jpg",
  },
  2024: {
    title: "Software Developer – ABC Corp",
    dates: "Jan 2024 – Present",
    description: "Worked on backend systems and cloud infrastructure at ABC Corp.",
    image: "./assets/exp-pic2.jpg",
  },
  2022: {
    title: "Intern – XYZ Ltd.",
    dates: "Jun 2022 – Sep 2022",
    description: "Assisted in full-stack development and QA testing.",
    image: "./assets/exp2022.jpg",
  },
  2020: {
    title: "Student Assistant – University of Leeds",
    dates: "Sep 2020 – May 2021",
    description: "Supported students in CS labs and tutoring sessions.",
    image: "./assets/exp2020.jpg",
  },
};
const years = document.querySelectorAll(".year");
const expTitle = document.getElementById("exp-title");
const expDates = document.getElementById("exp-dates");
const expDescription = document.getElementById("exp-description");
const expImage = document.getElementById("exp-image");

years.forEach((yearDiv) => {
  yearDiv.addEventListener("click", () => {
    const selectedYear = yearDiv.dataset.year;
    const data = experienceData[selectedYear];

    if (data) {
      expTitle.textContent = data.title;
      expDates.textContent = data.dates;
      expDescription.textContent = data.description;
      expImage.src = data.image;
      expImage.alt = `${data.title} image`;
    }
  });
});


// end of experience content