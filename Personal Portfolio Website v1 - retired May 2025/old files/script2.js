// JavaScript for dynamically adding projects
const projects = [
    { title: "Proactive Autoscaling in Kubernetes", description: "Virtualization, Containerization, Cloud Computing, Kubernetes, Autoscaling" },
    { title: "WIP", description: "Another awesome project on the way!." }
  ];
  
  const workexp = [
    { title: "BGC Group/ Cantor Fitzgerald", description: "I completed a DevOps-oriented internship here this summer as a technology (infrastructure) intern in the UNIX team."},
    { title: "Quantum Ventura", description: "la"}
  ];
  
  const workexpContainer = document.getElementById('workexp-container');
  
  workexp.forEach(workexp => {
    const weCard = document.createElement('div');
    weCard.classList.add('we-card');
  
    const weTitle = document.createElement('h3');
    weTitle.textContent = workexp.title;
  
    const weDesc = document.createElement('p');
    weDesc.textContent = workexp.description;
  
    weCard.appendChild(weTitle);
    weCard.appendChild(weDesc);
  
    workexpContainer.appendChild(weCard);
  });
  
  
  
  const projectsContainer = document.getElementById('projects-container');
  
  projects.forEach(project => {
    const projectCard = document.createElement('div');
    projectCard.classList.add('project-card');
  
    const projectTitle = document.createElement('h3');
    projectTitle.textContent = project.title;
    
    const projectDesc = document.createElement('p');
    projectDesc.textContent = project.description;
  
    projectCard.appendChild(projectTitle);
    projectCard.appendChild(projectDesc);
  
    projectsContainer.appendChild(projectCard);
  });
  
  // Handling contact form submission
  const contactForm = document.getElementById('contact-form');
  contactForm.addEventListener('submit', function(event) {
    event.preventDefault();
    alert("Thank you for your message!");
  });
  
  