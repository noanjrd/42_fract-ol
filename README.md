<!DOCTYPE html>
<html lang="fr">
<body>
    <header>
        <h1>Fract-ol</h1>
    </header>
    <main>
        <section>
            <h2>Introduction</h2>
            <p>Fract-ol est un projet passionnant qui explore le monde des fractales à travers des visualisations interactives. Ce programme permet de générer et d'explorer différentes fractales mathématiques, tout en offrant un contrôle précis sur les paramètres.</p>
        </section>
        <section>
            <h2>Fonctionnalités</h2>
            <ul>
                <li>Génération de plusieurs types de fractales : Mandelbrot, Julia, Burning Ship</li>
                <li>Contrôle interactif pour zoomer, dézoomer et explorer les fractales</li>
                <li>Prise en charge de différents paramètres pour personnaliser l'affichage</li>
                <li>Interface graphique fluide et réactive</li>
                <li>Couleurs des fractales générées aléatoirement</li>
            </ul>
        </section>
        <section>
            <h2>Prérequis</h2>
            <ul>
                <li><strong>Make</strong> : pour compiler le projet</li>
                <li><strong>gcc</strong> ou tout autre compilateur C compatible</li>
                <li><strong>X11</strong> et ses bibliothèques (exemple : Xlib, Xrandr)</li>
                <li><strong>minilibX</strong> (Se clone lors de make)</li>
            </ul>
        </section>
        <section>
            <h2>Installation</h2>
            <pre><code>git clone https://github.com/noanjrd/42_fract-ol
cd 42_fract-ol
make</code></pre>
        </section>
        <section>
            <h2>Utilisation</h2>
            <p>Lancez le programme en ligne de commande en spécifiant la fractale souhaitée :</p>
            <pre><code>./fract-ol [type_fractale]</code></pre>
            <h3>Types de fractales disponibles :</h3>
            <ul>
                <li>Mandelbrot</li>
                <li>Julia</li>
                <li>Burning_Ship</li>
            </ul>
            <p>Exemple :</p>
            <pre><code>./fract-ol Mandelbrot</code></pre>
            <h3>Commandes interactives :</h3>
            <ul>
                <li>Flèches directionnelles : déplacer la vue</li>
                <li>Molette de la souris : zoomer / dézoomer</li>
                <li>Touches q,w,a et s : ajuster les paramètres de la fractale Julia</li>
                <li>Échap : quitter le programme</li>
            </ul>
        </section>
        <section>
            <h2>Auteur</h2>
            <p>Projet réalisé par <strong>Noan Jard</strong>.</p>
        </section>
    </main>
    <footer>
        <p>Merci d'avoir consulté ce projet ! Si vous avez des questions, n'hésitez pas à ouvrir une issue ou à me contacter directement.</p>
    </footer>
</body>
</html>
