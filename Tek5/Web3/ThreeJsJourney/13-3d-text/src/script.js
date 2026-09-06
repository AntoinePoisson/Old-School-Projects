import * as THREE from 'three'
import { OrbitControls } from 'three/examples/jsm/controls/OrbitControls.js'
import * as dat from 'lil-gui'
import { FontLoader } from 'three/examples/jsm/loaders/FontLoader.js'
import { TextGeometry } from 'three/addons/geometries/TextGeometry.js';

/**
 * Base
 */
//? Convert a font:  https://gero3.github.io/facetype.js/

// const textureLoader = new THREE.TextureLoader()

// Debug
const gui = new dat.GUI()

console.time("Toto");
const fontLoader = new FontLoader()
fontLoader.load('/font/helvetiker_regular.typeface.json',
    (font) => {
        console.log("AZE");
        const geometry = new TextGeometry('Hello Antoine!', {
            font: font,
            size: 0.5,
            height: 0.2,
            curveSegments: 12,
            bevelEnabled: true,
            bevelThickness: 0.03,
            bevelSize: 0.02,
            bevelOffset: 0,
            bevelSegments: 5
        });
        geometry.computeBoundingBox()
        geometry.translate(
            - (geometry.boundingBox.max.x - geometry.parameters.options.bevelSize) / 2,
            - (geometry.boundingBox.max.y - geometry.parameters.options.bevelSize) / 2,
            - geometry.boundingBox.max.z * 0.5
        )
        //? Ou geometry.center()
        gui.add(geometry.parameters.options, 'size', 0, 50)
        gui.add(geometry.parameters.options, 'height', 0, 50)
        gui.add(geometry.parameters.options, 'curveSegments', 0, 50)
        gui.add(geometry.parameters.options, 'bevelEnabled')
        gui.add(geometry.parameters.options, 'bevelThickness', 0, 10)
        gui.add(geometry.parameters.options, 'bevelSize', 0, 10)
        gui.add(geometry.parameters.options, 'bevelOffset', 0, 50)
        gui.add(geometry.parameters.options, 'bevelSegments', 0, 50)

        const matcapTexture = textureLoader.load('/textures/matcaps/3.png')
        const matcapTexture2 = textureLoader.load('/textures/matcaps/6.png')
        const textMaterial = new THREE.MeshMatcapMaterial({ matcap: matcapTexture })
        const textMesh = new THREE.Mesh(geometry, textMaterial)
        scene.add(textMesh)
        const min = -10
        const max = 10

        const donutGeo = new THREE.TorusGeometry(0.2, 0.1)
        const donutMat = new THREE.MeshMatcapMaterial({ matcap: matcapTexture2 })
        for (let i = 0; i < 1000; i++) {
            const donutMesh = new THREE.Mesh(donutGeo, donutMat)
            donutMesh.position.set(geometry.boundingBox.max.x * -0.5 + Math.floor(Math.random() * (max - min + 1) + min), geometry.boundingBox.max.y * 1.5 + Math.floor(Math.random() * (max - min + 1) + min), geometry.boundingBox.max.z * 1.5 + Math.floor(Math.random() * (max - min + 1) + min))
            donutMesh.rotation.x = Math.random() * Math.PI
            const scale = Math.random()
            donutMesh.scale.set(scale, scale, scale)
            scene.add(donutMesh)
        }
        console.timeEnd("Toto")
    }
)





// Debug
// const gui = new dat.GUI()

// Canvas
const canvas = document.querySelector('canvas.webgl')

// Scene
const scene = new THREE.Scene()

scene.add(new THREE.AxesHelper(10))

/**
 * Textures
 */
const textureLoader = new THREE.TextureLoader()

/**
 * Object
 */
const cube = new THREE.Mesh(
    new THREE.BoxGeometry(1, 1, 1),
    new THREE.MeshBasicMaterial()
)

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
const camera = new THREE.PerspectiveCamera(75, sizes.width / sizes.height, 0.001, 100)
camera.position.x = 1
camera.position.y = 1
camera.position.z = 2
scene.add(camera)

// Controls
const controls = new OrbitControls(camera, canvas)
controls.enableDamping = true

/**
 * Renderer
 */
const renderer = new THREE.WebGLRenderer({
    canvas: canvas
})
renderer.setSize(sizes.width, sizes.height)
renderer.setPixelRatio(Math.min(window.devicePixelRatio, 2))

/**
 * Animate
 */
const clock = new THREE.Clock()

const tick = () => {
    const elapsedTime = clock.getElapsedTime()

    // Update controls
    controls.update()

    // Render
    renderer.render(scene, camera)

    // Call tick again on the next frame
    window.requestAnimationFrame(tick)
}

tick()