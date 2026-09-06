import * as dat from 'lil-gui'
import * as THREE from 'three'
import { OrbitControls } from 'three/examples/jsm/controls/OrbitControls.js'
import { GLTFLoader } from 'three/examples/jsm/loaders/GLTFLoader.js'
import { DRACOLoader } from 'three/examples/jsm/loaders/DRACOLoader.js'
import firefliesVertexShader from './shaders/fireflies/vertex.glsl'
import firefliesFragmentShader from './shaders/fireflies/fragment.glsl'
import portalVertexShader from './shaders/portal/vertex.glsl'
import portalFragmentShader from './shaders/portal/fragment.glsl'
import { FontLoader } from 'three/examples/jsm/loaders/FontLoader.js'
import { TextGeometry } from 'three/addons/geometries/TextGeometry.js';

/**
 * Base
 */

// Debug
const debugObject = {}
const gui = new dat.GUI({
    width: 400
})
gui.hide()

// Canvas
const canvas = document.querySelector('canvas.webgl')

// Scene
const scene = new THREE.Scene()

/**
 * Loaders
 */
// Texture loader
const textureLoader = new THREE.TextureLoader()

// Draco loader
const dracoLoader = new DRACOLoader()
dracoLoader.setDecoderPath('draco/')

// GLTF loader
const gltfLoader = new GLTFLoader()
gltfLoader.setDRACOLoader(dracoLoader)

/**
 * backed
 */
const bakedTexture = textureLoader.load('baked.jpg')
bakedTexture.flipY = false
bakedTexture.encoding = THREE.sRGBEncoding

const bakedMaterial = new THREE.MeshBasicMaterial({ map: bakedTexture, side: THREE.DoubleSide })
const poleLightMaterial = new THREE.MeshBasicMaterial({ color: 0xffffe5 })

debugObject.portalColorStart = '#ededed'
debugObject.portalColorEnd = '#1d1616'

const portalLightMaterial = new THREE.ShaderMaterial({
    uniforms:
    {
        uTime: { value: 0 },
        uColorStart: { value: new THREE.Color(debugObject.portalColorStart) },
        uColorEnd: { value: new THREE.Color(debugObject.portalColorEnd) },
    },
    vertexShader: portalVertexShader,
    fragmentShader: portalFragmentShader
})

gui
    .addColor(debugObject, 'portalColorStart')
    .onChange(() => {
        portalLightMaterial.uniforms.uColorStart.value.set(debugObject.portalColorStart)
    })

gui
    .addColor(debugObject, 'portalColorEnd')
    .onChange(() => {
        portalLightMaterial.uniforms.uColorEnd.value.set(debugObject.portalColorEnd)
    })

gltfLoader.load(
    'portal.glb',
    (gltf) => {
        // Get each object
        const bakedMesh = gltf.scene.children.find((child) => child.name === 'merged')
        const portalLightMesh = gltf.scene.children.find((child) => child.name === 'portalLight')
        const poleLightAMesh = gltf.scene.children.find((child) => child.name === 'poleLight')
        const poleLightBMesh = gltf.scene.children.find((child) => child.name === 'poleLight2')

        // Apply materials
        bakedMesh.material = bakedMaterial
        portalLightMesh.material = portalLightMaterial
        poleLightAMesh.material = poleLightMaterial
        poleLightBMesh.material = poleLightMaterial
        scene.add(gltf.scene)
    }
)

/**
 * Text
 */
const fontLoader = new FontLoader()
fontLoader.load('/font/helvetiker_regular.typeface.json',
    (font) => {
        const geometry = new TextGeometry('By Antoine', {
            font: font,
            size: 0.1,
            height: 0.01,
            curveSegments: 42,
            bevelEnabled: true,
            bevelThickness: 0.03,
            bevelSize: 0.01,
            bevelOffset: 0,
            bevelSegments: 5
        });
        // geometry.computeBoundingBox()
        // geometry.translate(
        //     -(geometry.boundingBox.max.x - geometry.parameters.options.bevelSize) / 1,
        //     (geometry.boundingBox.max.y - geometry.parameters.options.bevelSize) / 1,
        //     -geometry.boundingBox.max.z * 0.5
        // )
        //? Ou geometry.center()
        // gui.add(geometry.parameters.options, 'size', 0, 50)
        // gui.add(geometry.parameters.options, 'height', 0, 50)
        // gui.add(geometry.parameters.options, 'curveSegments', 0, 50)
        // gui.add(geometry.parameters.options, 'bevelEnabled')
        // gui.add(geometry.parameters.options, 'bevelThickness', 0, 10)
        // gui.add(geometry.parameters.options, 'bevelSize', 0, 10)
        // gui.add(geometry.parameters.options, 'bevelOffset', 0, 50)
        // gui.add(geometry.parameters.options, 'bevelSegments', 0, 50)

        const matcapTexture = textureLoader.load('/textures/matcaps/3.png')
        const textMaterial = new THREE.MeshMatcapMaterial({ matcap: matcapTexture })
        const textMesh = new THREE.Mesh(geometry, textMaterial)
        textMesh.position.set(-2.1, 0.1, 0.9)
        // textMesh.rotateY(Math.PI)
        textMesh.lookAt(new THREE.Vector3(-10, 5, 0.9))
        // textMesh.lookAt(camera.position)
        scene.add(textMesh)
    }
)


/**
 * Fireflies
 */
// Geometry
const firefliesGeometry = new THREE.BufferGeometry()
const firefliesCount = 30
const positionArray = new Float32Array(firefliesCount * 3)
const scaleArray = new Float32Array(firefliesCount)

for (let i = 0; i < firefliesCount; i++) {
    positionArray[i * 3 + 0] = (Math.random() - 0.5) * 4
    positionArray[i * 3 + 1] = Math.random() * 1.5
    positionArray[i * 3 + 2] = (Math.random() - 0.5) * 4
    scaleArray[i] = Math.random()
}

firefliesGeometry.setAttribute('position', new THREE.BufferAttribute(positionArray, 3))
firefliesGeometry.setAttribute('aScale', new THREE.BufferAttribute(scaleArray, 1))
const firefliesMaterial = new THREE.ShaderMaterial({
    uniforms:
    {
        uPixelRatio: { value: Math.min(window.devicePixelRatio, 2) },
        uSize: { value: 100 },
        uTime: { value: 0 },
    },
    transparent: true,
    blending: THREE.AdditiveBlending,
    depthWrite: false,
    vertexShader: firefliesVertexShader,
    fragmentShader: firefliesFragmentShader
})
const fireflies = new THREE.Points(firefliesGeometry, firefliesMaterial)
scene.add(fireflies)

gui.add(firefliesMaterial.uniforms.uSize, 'value').min(0).max(500).step(1).name('firefliesSize')


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

    // Update fireflies
    firefliesMaterial.uniforms.uPixelRatio.value = Math.min(window.devicePixelRatio, 2)
})

/**
 * Camera
 */
// Base camera
const camera = new THREE.PerspectiveCamera(45, sizes.width / sizes.height, 0.1, 100)
camera.position.x = -5
camera.position.y = 2.5
camera.position.z = 1
scene.add(camera)

// Controls
const controls = new OrbitControls(camera, canvas)
controls.enableDamping = true

/**
 * Renderer
 */
const renderer = new THREE.WebGLRenderer({
    canvas: canvas,
    antialias: true
})
renderer.setSize(sizes.width, sizes.height)
renderer.setPixelRatio(Math.min(window.devicePixelRatio, 2))
renderer.outputEncoding = THREE.sRGBEncoding

debugObject.clearColor = '#0d0c0c'
renderer.setClearColor(debugObject.clearColor)
gui.addColor(debugObject, 'clearColor')
    .onChange(() => {
        renderer.setClearColor(debugObject.clearColor)
    })

/**
 * Animate
 */
const clock = new THREE.Clock()

const tick = () => {
    const elapsedTime = clock.getElapsedTime()

    firefliesMaterial.uniforms.uTime.value = elapsedTime
    portalLightMaterial.uniforms.uTime.value = elapsedTime
    // Update controls
    controls.update()

    // Render
    renderer.render(scene, camera)

    // Call tick again on the next frame
    window.requestAnimationFrame(tick)
}

tick()