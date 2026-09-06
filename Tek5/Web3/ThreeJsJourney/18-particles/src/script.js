import * as THREE from 'three'
import { OrbitControls } from 'three/examples/jsm/controls/OrbitControls.js'
import * as dat from 'lil-gui'

/**
 * Base
 */
// Debug
const gui = new dat.GUI()

// Canvas
const canvas = document.querySelector('canvas.webgl')

// Scene
const scene = new THREE.Scene()

/**
 * Textures
 */
const textureLoader = new THREE.TextureLoader()

/**
 * Particule
 */
// const particleGeometry = new THREE.SphereGeometry(1, 32, 32)
const particleGeometry = new THREE.BufferGeometry()
const nbrParticume = 50000
const positions = new Float32Array(nbrParticume * 3)
const colors = new Float32Array(nbrParticume * 3)

for (let index = 0; index < positions.length; index++) {
    positions[index] = (Math.random() - 0.5) * 5
    colors[index] = Math.random()
}
particleGeometry.setAttribute('position', new THREE.BufferAttribute(positions, 3))
particleGeometry.setAttribute('color', new THREE.BufferAttribute(colors, 3))

const particuleTexture  = textureLoader.load('/textures/particles/3.png')

const particleMaterial = new THREE.PointsMaterial({
    size: 0.05,
    sizeAttenuation: true,
    color: 'pink',
    alphaMap: particuleTexture,
    transparent: true,
    alphaTest: 0.001, //? Permet de réglé un peu la superposition des pixels
    // depthTest: false, //? Permet de réglé un peu la superposition des pixels (Probleme quand il y a differentes elements)
    // depthWrite: true, //? Permet de réglé un peu la superposition des pixels (Marche le mieux)
    blending: THREE.AdditiveBlending, //? Impacte sur les performances
    vertexColors: true, //? Permet d'utiliser la color du vertex defini dans la geomtry
})

const particuleMesh = new THREE.Points(particleGeometry, particleMaterial)

// Text Cube
// const cube = new THREE.Mesh(
//     new THREE.BoxGeometry(),
//     new THREE.MeshBasicMaterial()
// )
// scene.add(cube)

scene.add(particuleMesh)

/**
 * Sizes
 */
const sizes = {
    width: window.innerWidth,
    height: window.innerHeight
}

window.addEventListener('resize', () =>
{
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
const camera = new THREE.PerspectiveCamera(75, sizes.width / sizes.height, 0.01, 500)
camera.position.z = 3
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
// renderer.setClearColor('grey')

/**
 * Animate
 */
const clock = new THREE.Clock()

const tick = () =>
{
    const elapsedTime = clock.getElapsedTime()

    // particuleMesh.rotation.x = elapsedTime * 0.1
    for (let index = 0; index < positions.length; index++) {
        let i3 = index * 3

        const x = particuleMesh.geometry.attributes.position.array[i3]
        particuleMesh.geometry.attributes["position"].array[i3 + 1] = Math.sin(elapsedTime + x)
    }
    particuleMesh.geometry.attributes["position"].needsUpdate = true
    // Update controls
    controls.update()

    // Render
    renderer.render(scene, camera)

    // Call tick again on the next frame
    window.requestAnimationFrame(tick)
}

tick()