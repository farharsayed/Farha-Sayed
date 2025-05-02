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
    }, { threshold: 0.5 }
);

// Observe all three elements
const animElements = document.querySelectorAll(".animated-title, .nav-title, .intro-text2, .exp-title2");
animElements.forEach((el) => {
    if (el) observer.observe(el);
});



const experienceData = {
    2025: {
        title: "Infrastructure and Cyber Security Engineer - Gulf Business Machines",
        dates: "Nov 2024 - Present",
        description: [
            "Provided security solutions for endpoint, network, servers and cloud email security to customers including MBZ University of Artificial Intelligence, ICP, ADEK, ADJD etc.",
            "Collaborated with vendors to implement products such as Trend Micro XDR/EDR and ASM, FortiSASE, BeyondTrust PRA, Cisco User Protection Suite etc.",
            "Executed the major rollout on several projects, managing up to 15,000 endpoints and servers",
            "Followed entire project lifecycles from pre-sales to documentation and closure."
        ],
        image: "./assets/exp-pic1.jpg",
    },
    2024: {
        title: "Infrastructure Technology Intern, UNIX - BGC Group (Cantor Fitzgerald)",
        dates: "July 2024 – Sept 2024",
        description: [
                "Migrated observability stack to scalable cloud-agnostic microservices on Red Hat OpenShift",
                "Deployed infrastructure and log management apps - Prometheus, Promtail, Grafana, Loki, Mimir and OTel",
                "Customized Docker images to adhere to security standards and meet platform-specific requirements",
                "Introduced Kubernetes, Helm charts and OpenShift via introductory demos to 15-20 team members",
                "Worked alongside team to learn about maintaining CentOS/Rocky Linux servers",
                "Researched the Java JMX Exporter to instrument Java applications and expose their metrics",
                "Used Nexus and Vault for artifact and secret management",
                "Learnt about PostgreSQL architecture, GitLab CI/CD and automation using Ansible AWX"
            ]
            // ,
            // image: "./assets/exp-pic2.jpg",
    },
    2022: {
        title: "Cyber Security Intern – Quantum Ventura",
        dates: "Jun 2022 – Sep 2022",
        description: [
                "Worked with a team of 5 on the launch of an NDR/EDR product to monitor, detect and visualize threats",
                "Explored the intricacies of network layers and investigated a range of cyber threats",
                "Evaluated softwares such as Apache Flink, Kafka, Zeek and ElasticSearch",
                "Analyzed market segments to effectively position product within the competitive landscape",
                "Conceptualized 10-15 dashboard features such as different dashboards for IT admins and senior leadership"
            ]
            // ,
            // image: "./assets/exp2022.jpg",
    },
    2020: {
        title: "Cyber Security Intern – Protiviti Global Business Consulting",
        dates: "Jul 2020 – Oct 2020",
        description: [
            "Learned about cybersecurity principles and network architecture, focusing on the foundational elements of secure systems.",
            "Explored the network layers, gaining an understanding of data transmission and communication protocols.",
            "Conducted research on common cyber threats, enhancing awareness of threat vectors and mitigation strategies."
        ]

        // ,
        // image: "./assets/exp2020.jpg",
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

const skillCards = document.querySelectorAll('.skill-card');
const popup = document.getElementById('skill-popup');

// Radial position logic
const radius = 200;
const container = document.querySelector('.mindmap-container');
const rect = container.getBoundingClientRect();
const centerX = rect.width / 2;
const centerY = rect.height / 2;

skillCards.forEach((card, i) => {
    const angle = (2 * Math.PI / skillCards.length) * i;
    const x = Math.cos(angle) * radius;
    const y = Math.sin(angle) * radius;

    // Position cards from the center
    card.style.position = 'absolute';
    card.style.top = '50%';
    card.style.left = '50%';
    card.style.transform = `translate(${x}px, ${y}px)`;
});

skillCards.forEach(card => {
    card.addEventListener('click', (e) => {
        const desc = card.dataset.desc;
        const rect = card.getBoundingClientRect();
        popup.style.left = `${rect.left + rect.width / 2}px`;
        popup.style.top = `${rect.top + window.scrollY + rect.height + 8}px`;
        popup.textContent = desc;
        popup.style.display = 'block';
    });
});

// Hide popup on outside click
document.addEventListener('click', (e) => {
    if (!e.target.closest('.skill-card')) {
        popup.style.display = 'none';
    }
});