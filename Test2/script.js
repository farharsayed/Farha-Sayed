

// functions for sidebar
function showSidebar() {
    const sidebar = document.querySelector('.sidebar')
    sidebar.style.display = 'flex'
}
function hideSidebar() {
    const sidebar = document.querySelector('.sidebar')
    sidebar.style.display = 'none'
}
function toggleSidebar() {
    const sidebar = document.querySelector('.sidebar');
    sidebar.classList.toggle('active'); // Toggle the 'active' class
}






// function for product buttons
function showText(id) {
    // Hide all textboxes
    const textboxes = document.querySelectorAll('.prod-desc');
    textboxes.forEach(box => box.style.display = 'none');
    
    // Show the selected textbox
    document.getElementById('pd' + id).style.display = 'block';



    const abcSection = document.getElementById('prod-buttons'); // Make sure ABC section has this ID
    if (abcSection) {
        abcSection.scrollIntoView({ behavior: 'smooth' }); // Smooth scroll
    }


}





// function to click and go back to home page
function navigateToHomePage() {
    window.location.href = 'index.html';
}