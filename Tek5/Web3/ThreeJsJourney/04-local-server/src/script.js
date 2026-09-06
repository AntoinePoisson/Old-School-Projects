import * as THREE from 'three';
import gsap from 'gsap'
import { OrbitControls } from 'three/examples/jsm/controls/OrbitControls';
import GUI from 'lil-gui';

// Event Cursor
const cursor = {
    x: 0,
    y: 0
}

// Handle mouse mouvement
window.addEventListener('mousemove', (event) => {
    cursor.x = event.clientX / sizes.width
    //? Reserve cause of browser coordinate
    cursor.y = -(event.clientY / sizes.height)
})

// Handle de resize
window.addEventListener('resize', (event) => {
    sizes.width = window.innerWidth;
    sizes.height = window.innerHeight
    aspectRatio = sizes.width / sizes.height

    camera.aspect = aspectRatio
    camera.updateProjectionMatrix()

    renderer.setSize(sizes.width, sizes.height)

    //? Permet d'éviter les especes de "step" sur les lignes (limite à 2 pour des questions de perf)
    renderer.setPixelRatio(Math.min(window.devicePixelRatio, 2))
})

// Handle de passé en fullscreen
window.addEventListener('dblclick', () => {
    //? Un peu complexe pour handle aussi Safari
    const fullscreenElement = document.fullscreenElement || document.webkitFullscreenElement

    if (!fullscreenElement) {
        if (canvas.requestFullscreen) {
            canvas.requestFullscreen()
        } else if (canvas.webkitRequestFullscreen) {
            canvas.webkitRequestFullscreen()
        }
    } else {
        if (document.exitFullscreen) {
            document.exitFullscreen()
        } else if (document.webkitExitFullscreen) {
            document.webkitExitFullscreen()
        }
    }
})

// Load Texture
//? Une autre manière de load (il y a encore une autre manière plus arcaique mais j'ai jugé pas utile)
// const image = new Image()
// const texture = new THREE.Texture(image)
// image.addEventListener('load', () =>
// {
//     texture.needsUpdate = true
// })
// image.src = '/textures/door/color.jpg'
const loadingManager = new THREE.LoadingManager()
loadingManager.onStart = () =>
{
    console.log('loading started')
}
loadingManager.onLoad = () =>
{
    console.log('loading finished')
}
loadingManager.onProgress = (url, loader, total) =>
{
    console.log('loading progressing', url, loader, total)
}
loadingManager.onError = () =>
{
    console.log('loading error')
}

const textureLoader = new THREE.TextureLoader(loadingManager)
const checkerboardTexture = textureLoader.load('/textures/checkerboard-1024x1024.png')
const heightTexture = textureLoader.load('/textures/door/height.jpg')
const normalTexture = textureLoader.load('/textures/door/normal.jpg')
const ambientOcclusionTexture = textureLoader.load('/textures/door/ambientOcclusion.jpg')
const metalnessTexture = textureLoader.load('/textures/door/metalness.jpg')
const roughnessTexture = textureLoader.load('/textures/door/roughness.jpg')
const colorTexture = textureLoader.load('/textures/door/color.jpg')
//? How many times the texture is repeated across the surface, in each direction U and V.
colorTexture.repeat.x = 2
colorTexture.repeat.y = 3
//? That is due to the texture not being set up to repeat itself by default. To change that, you have to update the wrapS and wrapT properties using the THREE.RepeatWrapping constant.
colorTexture.wrapS = THREE.RepeatWrapping
colorTexture.wrapT = THREE.RepeatWrapping
//? You can also alternate the direction with THREE.MirroredRepeatWrapping:
colorTexture.wrapS = THREE.MirroredRepeatWrapping
colorTexture.wrapT = THREE.MirroredRepeatWrapping
//? You can offset the texture using the offset property that is also a Vector2 with x and y properties. Changing these will simply offset the UV coordinates:
colorTexture.offset.x = 0.5
colorTexture.offset.y = 0.5
//? You can rotate the texture using the rotation property, which is a simple number corresponding to the angle in radians:
colorTexture.rotation = Math.PI * 0.25
//? The point around which rotation occurs.
colorTexture.center.x = 0.5
colorTexture.center.y = 0.5

//? Mip Map compression et filtrer (vraiment interresant comme feature)
colorTexture.minFilter = THREE.NearestFilter //* Mieux pour les performance
colorTexture.generateMipmaps = false //* Desactive le Mimap mieux pour le GPU, si minFilter = THREE.NearestFilter
// colorTexture.minFilter = THREE.LinearFilter
// colorTexture.minFilter = THREE.NearestMipmapNearestFilter
// colorTexture.minFilter = THREE.NearestMipmapLinearFilter
// colorTexture.minFilter = THREE.LinearMipmapNearestFilter
// colorTexture.minFilter = THREE.LinearMipmapLinearFilter
checkerboardTexture.minFilter = THREE.NearestFilter //* Mieux pour les performance
checkerboardTexture.magFilter = THREE.NearestFilter
//? Texture format and optimisation
/*
When you are preparing your textures, you must keep 3 crucial elements in mind:
    The weight
    The size (or the resolution)
    The data

- The weight
    Don't forget that the users going to your website will have to download those textures. You can use most of the types of images we use on the web like .jpg (lossy compression but usually lighter) or .png (lossless compression but usually heavier).
    Try to apply the usual methods to get an acceptable image but as light as possible. You can use compression websites like TinyPNG (also works with jpg) or any software.
- The size
    Each pixel of the textures you are using will have to be stored on the GPU regardless of the image's weight. And like your hard drive, the GPU has storage limitations. It's even worse because the automatically generated mipmapping increases the number of pixels that have to be stored.
    Try to reduce the size of your images as much as possible.
    If you remember what we said about the mipmapping, Three.js will produce a half smaller version of the texture repeatedly until it gets a 1x1 texture. Because of that, your texture width and height must be a power of 2. That is mandatory so that Three.js can divide the size of the texture by 2.
    Some examples: 512x512, 1024x1024 or 512x2048
    512, 1024 and 2048 can be divided by 2 until it reaches 1.
    If you are using a texture with a width or height different than a power of 2 value, Three.js will try to stretch it to the closest power of 2 number, which can have visually poor results, and you'll also get a warning in the console.
- The data
    We haven't tested it yet, because we have other things to see first, but textures support transparency. As you may know, jpg files don't have an alpha channel, so you might prefer using a png.
    Or you can use an alpha map, as we will see in a future lesson.
    If you are using a normal texture (the purple one), you will probably want to have the exact values for each pixel's red, green, and blue channels, or you might end up with visual glitches. For that, you'll need to use a png because its lossless compression will preserve the values.
    Where to find textures

Unfortunately, it's always hard to find the perfect textures. There are many websites, but the textures aren't always right, and you may have to pay.
It's probably a good idea to start by searching on the web. Here are some websites I frequently end up on.
    poliigon.com
    3dtextures.me
    arroway-textures.ch
Always make sure that you have the right to use the texture if it's not for personal usage.
You can also create your own using photos and 2D software like Photoshop or even procedural textures with software like Substance Designer.
*/


// Get Canvas
const canvas = document.querySelector('canvas.webgl')

// Scene
const scene = new THREE.Scene()

// Objects
const mesh1 = new THREE.Mesh(new THREE.BoxGeometry(1, 1, 1), new THREE.MeshBasicMaterial({ color: 0xffffff, map: colorTexture, wireframe: false }))
const mesh2 = new THREE.Mesh(new THREE.TorusKnotGeometry(), new THREE.MeshBasicMaterial({ color: 0x00ff00 }))
const mesh3 = new THREE.Mesh(new THREE.SphereGeometry(1, 32, 32), new THREE.MeshBasicMaterial({  wireframe: false, map: checkerboardTexture }))
const mesh5 = new THREE.Mesh(new THREE.TorusGeometry(1, 0.35, 32, 100), new THREE.MeshBasicMaterial({ color: 0x0ffff0 }))
const customGeometry = new THREE.BufferGeometry()
const positionArray = new Float32Array([
    0, 0, 0,
    0, 1, 0,
    1, 0, 0,
])
const positionAttribute = new THREE.BufferAttribute(positionArray, 3)
customGeometry.setAttribute('position', positionAttribute)
const mesh4 = new THREE.Mesh(customGeometry, new THREE.MeshBasicMaterial({ color: 0xff00ff, wireframe: true }))
mesh2.position.set(4, 0, 0)
mesh3.position.set(-2, 0, 0)
mesh4.position.set(0, 2, 0)
mesh5.position.set(0, -3, 0)
// Groups
const groupCube = new THREE.Group();
groupCube.add(mesh1)
groupCube.add(mesh2)
groupCube.add(mesh3)
groupCube.add(mesh4)
groupCube.add(mesh5)
// scale le groupe
// groupCube.scale.set(1, 1, 2)
scene.add(groupCube)

// AxeHelper
const axe = new THREE.AxesHelper(10)
scene.add(axe)

// Sizes ViewPort
const sizes = {
    width: window.innerWidth,
    height: window.innerHeight
}

// Camera
let aspectRatio = sizes.width / sizes.height
//?                                       FOV/  Ratio     /dis near/ dis far (si trop long provoque z-fighting renderer probleme)
const camera = new THREE.PerspectiveCamera(75, aspectRatio, 0.1, 100)
//* Other Camera
//  const camera = new THREE.OrthographicCamera(-1 *aspectRatio, 1 * aspectRatio, 1, -1, 0.1, 100)
camera.position.set(1, 1, 4)
scene.add(camera)

// controls
const controls = new OrbitControls(camera, canvas)
// controls.enabled = false
controls.enableDamping = true


// Debug
const gui = new GUI();
const folderDebug = gui.addFolder("Mesh1")
folderDebug.add(mesh1.position, 'y')
    .min(-10)
    .max(10)
    .step(0.1)
    .name("Pos Y")
folderDebug.add(mesh1, 'visible').name("Visible")
folderDebug.add(mesh1.material, 'wireframe').name('Wireframe')
folderDebug.addColor(mesh1.material, 'color').name("Color").onChange(console.log("New Color =>", mesh1.material.color))
folderDebug.add({
    spin: () => {
        gsap.to(mesh1.rotation, { y: mesh1.rotation.y + 10, duration: 1 })
    }
}, 'spin').name('Spinning')

// Renderer
const renderer = new THREE.WebGLRenderer({
    canvas
})
renderer.setSize(sizes.width, sizes.height)
renderer.setPixelRatio(Math.min(window.devicePixelRatio, 2))

// Three Clock
const clockCube = new THREE.Clock()

// Main Loop
const funcTick = () => {
    //* Custom Rotation
    //! groupCube.rotation.y = (0.1 * clockCube.getElapsedTime()) * Math.PI * 2
    // groupCube.position.x = Math.cos(clockCube.getElapsedTime())
    // groupCube.position.y = Math.sin(clockCube.getElapsedTime())

    //* Custom Control
    // camera.position.x = Math.sin(cursor.x * Math.PI * 2) * 5
    // camera.position.z = Math.cos(cursor.x * Math.PI * 2) * 5
    // camera.position.y = cursor.y * 3
    // camera.lookAt(groupCube.position)

    controls.update()
    renderer.render(scene, camera)
    window.requestAnimationFrame(funcTick)
}

funcTick()

//* GSAP
// gsap.to(groupCube.position, {x: 1, duration: 1, delay: 1})
