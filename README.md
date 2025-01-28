<!DOCTYPE html>
<html lang="en">
<body>
    <header>
        <h1>🌟 Fract-ol 🌟</h1>
    </header>
    <main>
        <section>
            <h2>📖 Introduction</h2>
            <p>Fract-ol is an exciting project within the core curriculum of 42 School. It explores the fascinating world of fractals through interactive visualizations, powered by the Minilibx library provided by 42. This program enables users to generate and explore various mathematical fractals with precise control over their parameters. 🌀</p>
        </section>
        <section>
            <h2>✨ Features</h2>
            <ul>
                <li>🖼️ Generation of multiple types of fractals: Mandelbrot, Julia, Burning Ship</li>
                <li>🎛️ Interactive controls for zooming, unzooming, and exploring fractals</li>
                <li>⚙️ Support for various parameters to customize the display</li>
                <li>💻 Smooth and responsive graphical interface</li>
                <li>🎨 Randomly generated fractal colors</li>
            </ul>
        </section>
        <section>
            <h2>📋 Requirements</h2>
            <ul>
                <li><strong>🛠️ Make</strong>: to compile the project</li>
                <li><strong>📦 gcc</strong> or any other compatible C compiler</li>
                <li><strong>🖥️ X11</strong> and its libraries (e.g., Xlib, Xrandr)</li>
            </ul>
        </section>
        <section>
            <h2>⚙️ Installation</h2>
            <pre><code>git clone https://github.com/noanjrd/42_fract-ol
cd 42_fract-ol
make</code></pre>
        </section>
        <section>
            <h2>🚀 Usage</h2>
            <p>Run the program from the command line by specifying the desired fractal:</p>
            <pre><code>./fract-ol [fractal_type]</code></pre>
            <h3>🌀 Available fractal types:</h3>
            <ul>
                <li>🌌 Mandelbrot</li>
                <li>🌟 Julia</li>
                <li>🔥 Burning_ship</li>
            </ul>
            <p>Example:</p>
            <pre><code>./fract-ol Mandelbrot</code></pre>
            <h3>🎮 Interactive controls:</h3>
            <ul>
                <li>⬅️➡️⬆️⬇️ Arrow keys: move the view</li>
                <li>🖱️ Mouse wheel: zoom in / zoom out</li>
                <li>⌨️ Keys q, w, a, and s: adjust parameters for the Julia fractal</li>
                <li>❌ Escape: quit the program</li>
            </ul>
        </section>
    <section>
        <h2>🌅 Screenshots</h2>
        <h3>Julia set</h3>
        <p align="">
        <img src="imgs/Julia.png" alt="Julia set screenshot" width="600" style="border-radius: 15;" />
        </p>
        <h3>Mandelbrot set</h3>
        <p align="">
        <img src="imgs/Mandelbrot.png" alt="Julia set screenshot" width="600" style="border-radius: 15;" />
        </p>
        <h3>Burning Ship set</h3>
        <p align="">
        <img src="imgs/Burning_ship.png" alt="Julia set screenshot" width="600" style="border-radius: 15;" />
        </p>
    </section>
        <section>
            <h2>👨‍💻 Author</h2>
            <p>Project made by <strong>Noan Jard</strong>. </p>
        </section>
    </main>
    <footer>
        <p>Thank you for checking out this project! If you have any questions, feel free to open an issue or contact me directly. 📩</p>
    </footer>
</body>
</html>
