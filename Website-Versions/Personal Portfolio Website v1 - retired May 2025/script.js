


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


   
  
  
//   // Function to toggle hamburger menu links visibility
//   function toggleMenu() {
//     const menuLinks = document.querySelector(".menu-links");
//     menuLinks.classList.toggle("active");
//   }
  


// function changeHeaderColor() {
//   const header = document.getElementById('header');
  
//   const sections = document.querySelectorAll('section'); // Assuming you have <section> tags
//   const options = {
//       threshold: 0.5, // When 50% of the section is in view
//   };

//   const observer = new IntersectionObserver((entries, observer) => {
//       entries.forEach(entry => {
//           if (entry.isIntersecting) {
//               // Change header color based on the section
//               switch (entry.target.id) {
//                   case 'about':
//                       header.style.backgroundColor = '#5d4d4c'; // Tomato for About
//                       break;
//                   case 'experience':
//                       header.style.backgroundColor = '#4682b4'; // SteelBlue for Experience
//                       break;
//                   case 'projects':
//                       header.style.backgroundColor = '#0D1632'; // LimeGreen for Projects
//                       break;
//                   case 'contact':
//                       header.style.backgroundColor = '#ff4500'; // OrangeRed for Contact
//                       break;
//                   default:
//                       header.style.backgroundColor = '#333'; // Default color
//               }
//           }
//       });
//   }, options);

//   sections.forEach(section => {
//       observer.observe(section);
//   });
// }

// changeHeaderColor(); // Initialize color changes




// work experience section:


  const items = document.querySelectorAll(".work-exp-item");
  const details = document.querySelectorAll(".work-exp-details");

  items.forEach((item) => {
    item.addEventListener("click", () => {
      // Remove active class from all items
      items.forEach((i) => i.classList.remove("active"));
      // Add active class to the clicked item
      item.classList.add("active");

      // Hide all details
      details.forEach((detail) => detail.classList.remove("active"));
      // Show the relevant details
      const companyId = item.getAttribute("data-company");
      document.getElementById(companyId).classList.add("active");
    });
  });

  // Set the default active item and detail
  document.querySelector(".work-exp-item").classList.add("active");
  document.querySelector(".work-exp-details").classList.add("active");

