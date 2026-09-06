

const scene = new THREE.Scene()

const geometry = new THREE.BoxGeometry(1, 1, 1)
const material = new THREE.MeshBasicMaterial({ color: 'red' })
const cube = new THREE.Mesh(geometry, material);

scene.add(cube)

const size = {
    width: 800,
    height: 600,
}

const camera = new THREE.PerspectiveCamera(75, size.width / size.height)

camera.position.z = 3
camera.position.y = 1
camera.position.x = 1

scene.add(camera)

const canvas = document.querySelector("canvas.webgl")

console.log("canvas", canvas)

const renderer = new THREE.WebGLRenderer({
    canvas: canvas
})

renderer.setSize(size.width, size.height)

renderer.render(scene, camera)
