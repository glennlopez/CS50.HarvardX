let burger = document.getElementById("burger");
let overlay = document.querySelector("section");
let heroImage = document.querySelector(".hero-image");
let showMenu = false;
let del = 3;
let i = 1;

let tl = gsap.timeline({
    repeat: -1,
    yoyo: true,
    ease: "expo.out"
});

overlay.style.display = "none";

burger.addEventListener("click", (e) => {
    showMenu = !showMenu;
    if (showMenu) {
        burger.classList.add("active");
        overlay.style.display = "block";
        gsap.to(overlay, 1, {
            clipPath: "polygon(0% 0%, 100% 0, 100% 100%, 0% 100%)",
            ease: "expo.in"
        });
    } else {
        burger.classList.remove("active");
        gsap.to(overlay, 1, {
            clipPath: "polygon(0% 0%, 100% 0%, 100% 0%, 0% 0%)",
            ease: "expo.out",
            onComplete: () => (overlay.style.display = "none")
        });
    }
});

gsap.set(["#hero-1 h2, #hero-1 h1, #hero-1 h3"], {
    clipPath: "polygon(0% 0%, 100% 0%, 100% 100%, 0% 100%)"
});

gsap.set(
    [
        `#hero-2 h2, #hero-3 h2, #hero-4 h2, #hero-5 h2,
     #hero-2 h1, #hero-3 h1, #hero-4 h1, #hero-5 h1,
     #hero-2 h3, #hero-3 h3, #hero-4 h3, #hero-5 h3`
    ],
    {
        clipPath: "polygon(0% 0%, 0% 0%, 0% 100%, 0% 100%)"
    }
);

while (i < 5) {
    tl.to(`#hero-${i} h2`, 0.9, {
        clipPath: "polygon(0% 0%, 0% 0%, 0% 100%, 0% 100%)",
        delay: del
    })
        .to(
            `#hero-${i} h1`,
            0.9,
            {
                clipPath: "polygon(0% 0%, 0% 0%, 0% 100%, 0% 100%)"
            },
            "-=0.3"
        )
        .to(
            `#hero-${i} h3`,
            0.9,
            {
                clipPath: "polygon(0% 0%, 0% 0%, 0% 100%, 0% 100%)"
            },
            "-=0.3"
        )
        .to(
            `#hero-${i} .hi-${i}`,
            0.7,
            {
                clipPath: "polygon(0% 0%, 0% 0%, 0% 100%, 0% 100%)"
            },
            "-=1"
        )
        .to(`#hero-${i + 1} h2`, 0.9, {
            clipPath: "polygon(0% 0%, 100% 0%, 100% 100%, 0% 100%)"
        })
        .to(
            `#hero-${i + 1} h1`,
            0.9,
            {
                clipPath: "polygon(0% 0%, 100% 0%, 100% 100%, 0% 100%)"
            },
            "-=0.3"
        )
        .to(
            `#hero-${i + 1} h3`,
            0.9,
            {
                clipPath: "polygon(0% 0%, 100% 0%, 100% 100%, 0% 100%)"
            },
            "-=0.3"
        );

    i++;
}