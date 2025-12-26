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





// hamburger menu


const hamburger = document.getElementById('hamburger');
const navLinks = document.querySelector('.nav-links');

hamburger.addEventListener('click', () => {
    navLinks.classList.toggle('active');
    hamburger.classList.toggle('toggle');
});











// for smaller devices, automatically runs every 3 seconds
function triggerStaggeredAnimation() {
    const elements = document.querySelectorAll(".animated-title, .nav-title, .intro-text2, .exp-title2");

    elements.forEach((el) => {
        el.classList.add("animate");

        setTimeout(() => {
            el.classList.remove("animate");

            el.querySelectorAll("span").forEach((span) => {
                span.style.removeProperty("transform");
            });
        }, 1000); // match animation duration
    });
}

// Run every 2s but only if viewport is below 768px
setInterval(() => {
    if (window.innerWidth <= 768) {
        triggerStaggeredAnimation();
    }
}, 2000);


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
    }, { threshold: 0.5 }
);

// Observe all three elements
const animElements = document.querySelectorAll(".animated-title, .nav-title, .intro-text2, .exp-title2, .skills-title2, .project-title2, .contact-title2");
animElements.forEach((el) => {
    if (el) observer.observe(el);
});



const experienceData = {
    2025: {
        title: "DevOps and Infrastructure Engineer - Gulf Business Machines",
        dates: "Nov 2024 - Present",
        description: [
            "Designed, implemented, and maintained on-prem Kubernetes infrastructure, optimizing cluster performance, resource utilization, and workload distribution for scalability and cost efficiency",
            "Installed and managed multiple instances of NVIDIA BCM & Run:ai for GPU orchestration",
            "Integrated n8n to automate cross-system workflows for data pipelines across AI infrastructure components",
            "Migrated and managed Docker images from public registries to internal offline Harbor Registry",
            "Built and maintained GitLab CI/CD pipelines ensuring smooth and automated deployments across clusters",
            "Worked with clusters on VMware Tanzu Kubernetes Grid Service on vSphere and Nutanix Kubernetes Platform(NKP) utilizing NFS, QNAP and MinIO backend storage",
            "Implemented Veeam Kasten for Kubernetes-native disaster recovery via snapshots and backups",
            "Coordinated with customers and project managers throughout project lifecycles, adhering to best practices in planning, automation, risk mitigation, and documentation"
            // "Implementing and managing Kubernetes infrastructure for air-gapped enterprise environments",
            // "Worked with clusters on Nutanix Kubernetes Platform (NKP) with Prism Central and Prism Element",
            // "Optimized VMware Tanzu Kubernetes Grid Service on vSphere across light and dark settings",
            // "Installed and configured NVIDIA BCM to support Run:ai for efficient GPU utilization by AI/ML workloads",
            // "Implemented Harbor Registry for artifact management and Veeam Kasten for Kubernetes-native DR",
            // "Secured up to 15,000 endpoints and servers using ManageEngine Endpoint Central and Ansible playbooks",
            // "Collaborated with vendors to integrate advanced ZTNA, EPP and PAM solutions"
        ],
        image: "./assets/exp-pic1.jpg",
    },
    2024: {
        title: "Infrastructure Technology Intern, UNIX - BGC Group",
        dates: "July 2024 – Sept 2024",
        description: [
            "Led migration of observability stack (Prometheus, Promtail, Grafana, Loki, Mimir and OTel) to scalable cloud-agnostic microservices on Red Hat OpenShift",
            "Introduced Kubernetes, Helm charts and OpenShift via introductory demos to 20 team members",
            "Used Nexus and Hashicorp Vault for artifact and secret management",
            "Customized Docker images to adhere to security standards and meet platform-specific requirements",
            "Learnt about PostgreSQL architecture, GitLab CI/CD, automation using Ansible AWX and Java JMX Exporter to instrument Java apps"
        ],
        image: "./assets/exp-pic2.jpg",
    },
    2022: {
        title: "Cybersecurity Intern – Quantum Ventura",
        dates: "Jun 2022 – Sep 2022",
        description: [
            "Worked on the development of an NDR/EDR product using artificial intelligence to monitor logs, detect and visualize threats",
            "Evaluated tools such as Apache Flink, Kafka, Zeek and ElasticSearch to find the best fit for the product",
            "Analyzed market segments to effectively position product within the competitive landscape",
            "Conceptualized dashboard features such as automatically generating low-level reports for IT admins and high-level summaries for senior leadership"
        ],
        image: "./assets/exp-pic3.png",
    },
    2020: {
        title: "Cybersecurity Intern – Protiviti Global Business Consulting",
        dates: "Jul 2020 – Oct 2020",
        description: [
            "Learned about cybersecurity principles and network architecture, focusing on the foundational elements of secure systems.",
            "Explored the network layers, gaining an understanding of data transmission and communication protocols.",
            "Conducted research on common cyber threats, enhancing awareness of threat vectors and mitigation strategies."
        ]

        ,
        image: "./assets/exp-pic4.png",
    },
};

const years = document.querySelectorAll(".year");
const expTitle = document.getElementById("exp-title-jobs");
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

            // Clear and populate description
            expDescription.innerHTML = "";
            if (Array.isArray(data.description)) {
                const ul = document.createElement("ul");
                data.description.forEach((item) => {
                    const li = document.createElement("li");
                    li.textContent = item;
                    ul.appendChild(li);
                });
                expDescription.appendChild(ul);
            } else {
                expDescription.textContent = data.description;
            }

            // expImage.src = data.image;
            if (data.image) {
                expImage.src = data.image;
                expImage.alt = `${data.title} image`;
                expImage.style.display = "block";
                document.getElementById("experience-content").classList.remove("no-image");
            } else {
                expImage.style.display = "none";
                expImage.src = "";
                expImage.alt = "";
                document.getElementById("experience-content").classList.add("no-image");
            }

        }
    });
});


// end of experience content



//start of skills



// managing when a skill is selected

const skillData = {
    html: {
        title: "HTML",
        description: "I used HTML, CSS and JS to build this website!"
    },
    css: {
        title: "CSS",
        description: "I used HTML, CSS and JS to build this website!"
    },
    javascript: {
        title: "JavaScript",
        description: "I used HTML, CSS and JS to build this website!"
    },
    redhat: {
        title: "Red Hat",
        description: "I completed the RH199 course to prepare for the RHCSA exam. Additionally, I exclusively worked on OpenShift during my time at BGC."
    },
    java: {
        title: "Java Programming Language",
        description: ""
    },
    azure: {
        title: "Microsoft Azure",
        description: "I managed 5 clusters on Microsoft Azure for my research project: 'Proactive Autoscaling in Kubernetes'. You can find more details in my Github."
    },
    C: {
        title: "C Programming Language",
        description: "I designed a compiler for the JACK programming language using C, including components such as the lexer and parser."
    },
    aws: {
        title: "AWS",
        description: "I have run a few personal projects on AWS and I am CCP certified, currently preparing for SAA!"
    },
    docker: {
        title: "Docker",
        description: ""
    },
    gitlab: {
        title: "GitLab",
        description: ""
    },
    openshift: {
        title: "OpenShift",
        description: ""
    },
    kubernetes: {
        title: "Kubernetes",
        description: ""
    },
    python: {
        title: "Python",
        description: ""
    },
    grafana: {
        title: "Grafana",
        description: ""
    },
    prometheus: {
        title: "Prometheus",
        description: ""
    }
};


const logos = document.querySelectorAll('.skill-card');
const detailBox = document.getElementById('skillDetails');
const skillText = document.getElementById('skillText');

const skillTitle = document.getElementById('skillTitle');
const closeBtn = document.getElementById('closeBtn');

logos.forEach(logo => {
    logo.addEventListener('click', () => {
        const skill = logo.dataset.skill;

        // Add move-left to all except the clicked one
        logos.forEach(el => {
            el.classList.add('move-left');
            el.classList.remove('active');
        });
        logo.classList.add('active');




        // Populate title and description
        if (skillData[skill]) {
            skillTitle.textContent = skillData[skill].title;
            skillText.textContent = skillData[skill].description || "More info coming soon.";
        } else {
            skillTitle.textContent = skill;
            skillText.textContent = "No information available.";
        }
        detailBox.classList.add('show');
    });
});

closeBtn.addEventListener('click', () => {
    logos.forEach(el => {
        el.classList.remove('move-left', 'active');
        el.style.opacity = 1;
    });
    detailBox.classList.remove('show');
});







// when clicked, animate other icons

const cardsPerRow = 5;

logos.forEach((logo, index) => {
    logo.dataset.index = index; // assign index if not already
    logo.addEventListener('click', () => {
        const clickedIndex = parseInt(logo.dataset.index);
        const clickedRow = Math.floor(clickedIndex / cardsPerRow);

        logos.forEach((el, i) => {
            const thisRow = Math.floor(i / cardsPerRow);

            if (i === clickedIndex) {
                el.classList.add('active');
                el.classList.remove('move-left');
            } else {
                el.classList.remove('active');

                // Only move cards in other rows
                if (thisRow !== clickedRow) {
                    el.classList.add('move-left');
                } else {
                    el.classList.remove('move-left');
                }

                el.style.opacity = 0.3;
            }
        });

        skillText.textContent = skills[logo.dataset.skill];
        skillTitle.textContent = skillTitles[logo.dataset.skill];
        detailBox.classList.add('show');
    });
});