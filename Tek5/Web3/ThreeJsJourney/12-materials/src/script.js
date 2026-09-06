import * as THREE from 'three'
import { OrbitControls } from 'three/examples/jsm/controls/OrbitControls.js'
import GUI from 'lil-gui'

/**
 * Base
 */
// Canvas
const canvas = document.querySelector('canvas.webgl')

// Scene
const scene = new THREE.Scene()

// Light
//!
const ambientLight = new THREE.AmbientLight(0xffffff, 0.4)
scene.add(ambientLight)
const pointLight = new THREE.PointLight(0xffffff, 0.5)
pointLight.position.x = 2
pointLight.position.y = 3
pointLight.position.z = 4
scene.add(pointLight)
//!

// Texture
const loadingManager = new THREE.LoadingManager(() => { console.log("OK load"); })
//? hdrihaven.com pour récup des enviroment de map
//? Convert hdri to cubrMap: https://matheowis.github.io/HDRI-to-CubeMap/
const cubeTextureLoader = new THREE.CubeTextureLoader(loadingManager).load([
    '/textures/environmentMaps/3/px.jpg',
    '/textures/environmentMaps/3/nx.jpg',
    '/textures/environmentMaps/3/py.jpg',
    '/textures/environmentMaps/3/ny.jpg',
    '/textures/environmentMaps/3/pz.jpg',
    '/textures/environmentMaps/3/nz.jpg'
])

const textureLoader = new THREE.TextureLoader(loadingManager)
const doorColorTexture = textureLoader.load('/textures/door/color.jpg')
const doorAlphaTexture = textureLoader.load('/textures/door/alpha.jpg')
const doorAmbientOcclusionTexture = textureLoader.load('/textures/door/ambientOcclusion.jpg')
const doorHeightTexture = textureLoader.load('/textures/door/height.jpg')
const doorNormalTexture = textureLoader.load('/textures/door/normal.jpg')
const doorMetalnessTexture = textureLoader.load('/textures/door/metalness.jpg')
const doorRoughnessTexture = textureLoader.load('/textures/door/roughness.jpg')
const matcapTexture = textureLoader.load('/textures/matcaps/8.png')
const gradientTexture = textureLoader.load('/textures/gradients/5.jpg')
// Object
// const material = new THREE.MeshNormalMaterial({
//     flatShadding: true,
//     wireframe: false,
// })

// const material = new THREE.MeshLambertMaterial({})
// material.side = THREE.DoubleSide

// const material = new THREE.MeshDepthMaterial({})
// material.side = THREE.DoubleSide

// const material = new THREE.MeshPhongMaterial({shininess: 1000, specular: new THREE.Color('green')})
// material.side = THREE.DoubleSide

// gradientTexture.minFilter = THREE.NearestFilter
// gradientTexture.miagFilter = THREE.NearestFilter
// gradientTexture.generateMipmaps = false
// const material = new THREE.MeshToonMaterial({gradientMap: gradientTexture})
// material.side = THREE.DoubleSide

const material = new THREE.MeshStandardMaterial({metalness: 0.8, roughness: 0.2})
material.side = THREE.DoubleSide
material.envMap = cubeTextureLoader
// material.map = doorColorTexture
// material.aoMap = doorAmbientOcclusionTexture
// material.aoMapIntensity = 6
// material.displacementMap = doorHeightTexture
// material.displacementScale = 0.1
// material.metalnessMap = doorMetalnessTexture
// material.roughnessMap = doorRoughnessTexture
// material.normalMap = doorNormalTexture
// material.normalScale.set(1, 1)
// material.alphaMap = doorAlphaTexture
// material.transparent = true

material.envMap
material.map
material.aoMap
material.aoMapIntensity
material.displacementMap
material.displacementScale
material.metalnessMap
material.roughnessMap
material.normalMap
material.normalScale
material.alphaMap

//! https://github.com/nidorx/matcaps
// const material = new THREE.MeshMatcapMaterial({
//     matcap: matcapTexture
// })
// material.side = THREE.DoubleSide

// const material = new THREE.MeshBasicMaterial({
//     color: 0xffff00,
//     wireframe: false,
//     map: doorColorTexture
// })
// //! move
// material.opacity = 0.90
// material.transparent = true
// material.alphaMap = doorAmbientOcclusionTexture
// material.side = THREE.DoubleSide //? pas ouf pour la performance
// material.flatShadding = true
// //

const sphere = new THREE.Mesh(
    new THREE.SphereGeometry(0.5, 128, 128),
    material
)
sphere.position.x = - 1.5
sphere.geometry.setAttribute('uv2', new THREE.BufferAttribute(sphere.geometry.attributes.uv.array, 2))

const plane = new THREE.Mesh(
    new THREE.PlaneGeometry(1, 1, 128, 128),
    material
)
plane.geometry.setAttribute('uv2', new THREE.BufferAttribute(plane.geometry.attributes.uv.array, 2))

const torus = new THREE.Mesh(
    new THREE.TorusGeometry(0.3, 0.1, 8, 32),
    // new THREE.MeshNormalMaterial({flatShading: true})
    material
)
torus.position.x = 1.5

// Debug
const gui = new GUI()
gui.add(material, 'metalness', 0, 1)
gui.add(material, 'roughness', 0, 1)
gui.add(material, 'aoMapIntensity', 0, 10)
gui.add(material, 'wireframe')
gui.add(material, 'displacementScale', 0, 1)


scene.add(sphere, plane, torus)

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

    sphere.rotation.y = 0.1 * clock.elapsedTime
    plane.rotation.y = 0.1 * clock.elapsedTime
    torus.rotation.y = 0.1 * clock.elapsedTime

    sphere.rotation.x = 0.1 * clock.elapsedTime
    plane.rotation.x = 0.1 * clock.elapsedTime
    torus.rotation.x = 0.1 * clock.elapsedTime

    // Update controls
    controls.update()

    // Render
    renderer.render(scene, camera)

    // Call tick again on the next frame
    window.requestAnimationFrame(tick)
}

tick()