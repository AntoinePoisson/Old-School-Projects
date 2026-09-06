import * as THREE from 'three'
import { OrbitControls } from 'three/examples/jsm/controls/OrbitControls.js'
import * as dat from 'lil-gui'
import { GLTFLoader } from 'three/examples/jsm/loaders/GLTFLoader.js'

/**
 * Loader
 */

const cubeTextureLoader = new THREE.CubeTextureLoader()

const gltfLoader = new GLTFLoader()
gltfLoader.load(
    '/models/FlightHelmet/glTF/FlightHelmet.gltf',
    (gltf) => {
        console.log('success')
        gltf.scene.scale.set(10, 10, 10)
        gltf.scene.position.set(0, - 4, 0)
        gltf.scene.rotation.y = Math.PI * 0.5
        scene.add(gltf.scene)
        gui.add(gltf.scene.rotation, 'y').min(- Math.PI).max(Math.PI).step(0.001).name('rotation')
        updateAllMaterials()
    }
)

/**
 * Base
 */
// Debug
const gui = new dat.GUI()
const debugObject = {}

// Canvas
const canvas = document.querySelector('canvas.webgl')

// Scene
const scene = new THREE.Scene()

/**
 * Update all materials
 */
const updateAllMaterials = () => {
    scene.traverse((child) => {
        if (child instanceof THREE.Mesh && child.material instanceof THREE.MeshStandardMaterial) {
            child.material.envMap = environmentMapTexture
            child.material.envMapIntensity = debugObject.envMapIntensity
            child.castShadow = true
            child.receiveShadow = true
        }
    })
}

const environmentMapTexture = cubeTextureLoader.load([
    '/textures/environmentMaps/0/px.jpg',
    '/textures/environmentMaps/0/nx.jpg',
    '/textures/environmentMaps/0/py.jpg',
    '/textures/environmentMaps/0/ny.jpg',
    '/textures/environmentMaps/0/pz.jpg',
    '/textures/environmentMaps/0/nz.jpg'
])
environmentMapTexture.encoding = THREE.sRGBEncoding
scene.background = environmentMapTexture
//? Une autre manière de apply l'envMap sur les Mesh
// scene.environment = environmentMap

debugObject.envMapIntensity = 2.5
gui.add(debugObject, 'envMapIntensity').min(0).max(10).step(0.001).onChange(updateAllMaterials)
/**
 * Test sphere
 */
const testSphere = new THREE.Mesh(
    new THREE.SphereGeometry(1, 32, 32),
    new THREE.MeshStandardMaterial()
)
scene.add(testSphere)

/**
 * Lights
 */
const directLight = new THREE.DirectionalLight('white', 3)
directLight.position.set(0.25, 3, -2.25)
scene.add(directLight)
gui.add(directLight, 'intensity').min(0).max(10).step(0.001).name('lightIntensity')
gui.add(directLight.position, 'x').min(- 5).max(5).step(0.001).name('lightX')
gui.add(directLight.position, 'y').min(- 5).max(5).step(0.001).name('lightY')
gui.add(directLight.position, 'z').min(- 5).max(5).step(0.001).name('lightZ')

/**
 * Sizes
 */
const sizes = {
    width: window.innerWidth,
    height: window.innerHeight
}

window.addEventListener('resize', () => {
    // Update sizes
    sizes.width = window.innerWidth
    sizes.height = window.innerHeight

    // Update camera
    camera.aspect = sizes.width / sizes.height
    camera.updateProjectionMatrix()

    // Update renderer
    renderer.setSize(sizes.width, sizes.height)
    renderer.setPixelRatio(Math.min(window.devicePixelRatio, 2))
})

/**
 * Camera
 */
// Base camera
const camera = new THREE.PerspectiveCamera(75, sizes.width / sizes.height, 0.1, 100)
camera.position.set(4, 1, - 4)
scene.add(camera)

// Controls
const controls = new OrbitControls(camera, canvas)
controls.enableDamping = true

/**
 * Renderer
 */
const renderer = new THREE.WebGLRenderer({
    canvas: canvas,
    antialias: true,
    /*
    It's a well-known problem. When the rendering of a pixel occurs, it tests what geometry is being rendered in that pixel.
    It calculates the color, and, in the end, that color appears on the screen.

    But geometry edges are usually not perfectly aligned with vertical lines and horizontal lines of pixel of your screen and
    this is why you get this stair-like artifact named aliasing.

    There are many ways of fixing that problem, and developers have been struggling with it for many years.

    One easy solution would be to increase our render's resolution, let's say to the double. When resized to it's normal-sized,
    each pixel color will automatically be averaged from the 4 pixels rendered.

    This solution is called super sampling (SSAA) or fullscreen sampling (FSAA), and it's the easiest and more efficient one. Unfortunately,
    that means 4 times more pixels to render, which can result in performance issues.

    The other solution is called multi sampling (MSAA). Again, the idea is to render multiple values per pixel (usually 4)
    like for the super sampling but only on the geometries' edges. The values of the pixel are then averaged to get the final pixel value.

    The most recent GPU can perform this multi sampling anti-aliasing, and Three.js handles the setup automatically.
    We just need to change the antialias property to true during the instantiating — and not after:
    */
})
renderer.setSize(sizes.width, sizes.height)
renderer.setPixelRatio(Math.min(window.devicePixelRatio, 2))
renderer.physicallyCorrectLights = true //? La light plus r"aliste
renderer.outputEncoding = THREE.sRGBEncoding
//? explication de outputEncoding:
/*
You should see much brighter textures that will also impact the environment map.
Another possible value is THREE.GammaEncoding. This encoding has the advantage of
letting you play on a value called gammaFactor that would act a little like the brightness,
but we won't use this one in the lesson.
The Gamma Encoding is a way of storing colors while optimizing how bright and dark
values are stored according to human eye sensitivity. When we use the sRGBEncoding,
it's like using the GammaEncoding with a default gamma factor of 2.2, which is the common value.
*/
renderer.toneMapping = THREE.ACESFilmicToneMapping
//? Explication:
/*
he tone mapping intends to convert High Dynamic Range (HDR) values to Low Dynamic Range (LDR) values.
HDR is much more than the following interpretation, but you can see that like images where the color values can go beyond 1.
It's useful if we want to store light information because light doesn't have intensity limits.

While our assets are not HDR, the tone mapping effect can have a realistic result as if the camera was poorly adjusted.

To change the tone mapping, update the toneMapping property on the WebGLRenderer.

There are multiple possible values:

    THREE.NoToneMapping (default)
    THREE.LinearToneMapping
    THREE.ReinhardToneMapping
    THREE.CineonToneMapping
    THREE.ACESFilmicToneMapping
*/
gui.add(renderer, 'toneMapping', {
    No: THREE.NoToneMapping,
    Linear: THREE.LinearToneMapping,
    Reinhard: THREE.ReinhardToneMapping,
    Cineon: THREE.CineonToneMapping,
    ACESFilmic: THREE.ACESFilmicToneMapping
})
renderer.toneMappingExposure = 0.85
gui.add(renderer, 'toneMappingExposure').min(0).max(10).step(0.001)
/*
We can also change the tone mapping exposure.
You can see that like how much light we let in and the algorithm will handle it its way.
To change this value, we must update the toneMappingExposure property directly on the renderer:
*/
renderer.shadowMap.enabled = true
renderer.shadowMap.type = THREE.PCFSoftShadowMap
directLight.castShadow = true
directLight.shadow.camera.far = 15
directLight.shadow.mapSize.set(1024, 1024)
directLight.shadow.normalBias = 0.05
// directLight.shadow.bias = 0.05 //? for flat surface
//? Shadow acne
/*
These artifacts are called shadow acne. Shadow acne can occur on both smooth and
flat surfaces for precision reasons when calculating if the surface is in the shadow or not. What's happening
here is that the hamburger is casting a shadow on its own surface.

We have to tweak the light shadow's bias and normalBias properties to fix this shadow acne.

The bias usually helps for flat surfaces. It's not our case here, but if you have the problem on flat surfaces,
try to increase the bias slightly until the acne disappears.
*/

/**
 * Animate
 */
const tick = () => {
    // Update controls
    controls.update()

    // Render
    renderer.render(scene, camera)

    // Call tick again on the next frame
    window.requestAnimationFrame(tick)
}

tick()