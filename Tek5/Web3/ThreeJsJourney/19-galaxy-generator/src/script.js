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
 * Test cube
 */
const parameters = {
    count: 90000,
    size: 0.01,
    radius: 5,
    branching: 4,
    spin: 1,
    randomness: 0.2,
    randomnessPow: 6,
    insideColor: '#ff6030',
    outsideColor: '#1b3984',
}

let geometry = null
let material = null
let particles = null

const genGalaxy = () => {
    if (particles !== null) {
        geometry.dispose()
        material.dispose()
        scene.remove(particles)
    }
    geometry = new THREE.BufferGeometry();
    material = new THREE.PointsMaterial({
        size: parameters.size,
        sizeAttenuation: true,
        depthWrite: false,
        blending: THREE.AdditiveBlending,
        // color: '#ff5588',
        vertexColors: true
    })
    const vertexArray = new Float32Array(parameters.count * 3)
    const vertexArrayColor = new Float32Array(parameters.count * 3)

    const colorInside = new THREE.Color(parameters.insideColor)
    const colorOutside = new THREE.Color(parameters.outsideColor)

    for (let index = 0; index < parameters.count; index++) {
        const radius = Math.random() * parameters.radius
        const spinAngle = radius * parameters.spin
        const branchAngle = ((index % parameters.branching) / parameters.branching) * (2 * Math.PI)

        const randomX = Math.pow((Math.random()), parameters.randomnessPow) * (Math.random() < 0.5 ? 1 : -1)
        const randomY = Math.pow((Math.random()), parameters.randomnessPow) * (Math.random() < 0.5 ? 1 : -1)
        const randomZ = Math.pow((Math.random()), parameters.randomnessPow) * (Math.random() < 0.5 ? 1 : -1)

        vertexArray[index * 3] = (Math.sin(branchAngle + spinAngle) * radius) + randomX
        vertexArray[index * 3 + 1] = randomY * 0.5
        vertexArray[index * 3 + 2] = (Math.cos(branchAngle + spinAngle) * radius) + randomZ

        const mixColor = colorInside.clone().lerp(colorOutside, radius / parameters.radius)
        vertexArrayColor[index * 3] = mixColor.r
        vertexArrayColor[index * 3 + 2] = mixColor.g
        vertexArrayColor[index * 3 + 3] = mixColor.b
    }
    geometry.setAttribute('position', new THREE.BufferAttribute(vertexArray, 3))
    geometry.setAttribute('color', new THREE.BufferAttribute(vertexArrayColor, 3))

    particles = new THREE.Points(geometry, material)
    scene.add(particles)
}
genGalaxy()

const galaxyGUIFolder = gui.addFolder("Galaxy")
//? onChange update a chaque chagement de value dans gui et onFinishChange update une fois une valeur fixé
galaxyGUIFolder.add(parameters, 'count').min(100).max(1000000).step(10).onFinishChange(genGalaxy)
galaxyGUIFolder.add(parameters, 'size').min(0.001).max(1).step(0.001).onFinishChange(genGalaxy)
galaxyGUIFolder.add(parameters, 'radius').min(0.001).max(20).step(0.01).onFinishChange(genGalaxy)
galaxyGUIFolder.add(parameters, 'branching').min(2).max(20).step(1).onFinishChange(genGalaxy)
galaxyGUIFolder.add(parameters, 'spin').min(- 5).max(5).step(0.001).onFinishChange(genGalaxy)
galaxyGUIFolder.add(parameters, 'randomness').min(0).max(2).step(0.001).onFinishChange(genGalaxy)
galaxyGUIFolder.add(parameters, 'randomnessPow').min(0.5).max(10).step(0.001).onFinishChange(genGalaxy)
galaxyGUIFolder.addColor(parameters, 'insideColor').onFinishChange(genGalaxy)
galaxyGUIFolder.addColor(parameters, 'outsideColor').onFinishChange(genGalaxy)

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
const camera = new THREE.PerspectiveCamera(75, sizes.width / sizes.height, 0.01, 500)
camera.position.x = 3
camera.position.y = 3
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