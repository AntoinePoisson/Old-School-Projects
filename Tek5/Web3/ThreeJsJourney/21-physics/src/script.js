import * as THREE from 'three'
import { OrbitControls } from 'three/examples/jsm/controls/OrbitControls.js'
import * as dat from 'lil-gui'
import CANNON, { Material } from 'cannon'

/**
 * Debug
 */
const gui = new dat.GUI()
const debugObject = {
    createSphere: () => createSphere(
        Math.random() * 0.5 + 0.2,
        {
            x: (Math.random() - 0.5) * 3,
            y: 3,
            z: (Math.random() - 0.5) * 3
        }
    ),
    createBox: () => createBox(
        Math.random() * 2 + 0.5,
        Math.random() * 2 + 0.5,
        Math.random() * 2 + 0.5,
        {
            x: (Math.random() - 0.5) * 3,
            y: 3,
            z: (Math.random() - 0.5) * 3
        }
    ),
    reset: () => {
        for(const object of objectsToUpdate)
        {
            // Remove body
            object.body.removeEventListener('collide', playHitSound)
            world.removeBody(object.body)

            // Remove mesh
            scene.remove(object.mesh)
        }
        objectsToUpdate.splice(0, objectsToUpdate.length)
    }
}
gui.add(debugObject, 'createSphere')
gui.add(debugObject, 'createBox')
gui.add(debugObject, 'reset')

//? 2D lib:
/*
For 2D physics, there are many libraries, but here's the most popular:
Matter.js
    Website: https://brm.io/matter-js/
    Git repository: https://github.com/liabru/matter-js
    Documentation: https://brm.io/matter-js/docs/
    Mostly maintained by one developer
    Still kind of updated

P2.js
    Website: https://schteppe.github.io/p2.js/
    Git repository: https://github.com/schteppe/p2.js
    Documentation: http://schteppe.github.io/p2.js/docs/
    Mostly maintained by one developer (Same as Cannon.js)
    Hasn't been update for 2 years

Planck.js
    Website: https://piqnt.com/planck.js/
    Git repository: https://github.com/shakiba/planck.js
    Documentation: https://github.com/shakiba/planck.js/tree/master/docs
    Mostly maintained by one developer
    Still updated nowadays

Box2D.js
    Website: http://kripken.github.io/box2d.js/demo/webgl/box2d.html
    Git repository: https://github.com/kripken/box2d.js/
    Documentation: No documentation
    Mostly maintained by one developer (same as Ammo.js)
    Still updated nowadays

*/

//? 3D lib:
/*
Ammo.js
    Website: http://schteppe.github.io/ammo.js-demos/
    Git repository: https://github.com/kripken/ammo.js/
    Documentation: No documentation
    Direct JavaScript port of Bullet (a physics engine written in C++)
    A little heavy
    Still updated by a community

Cannon.js
    Website: https://schteppe.github.io/cannon.js/
    Git repository: https://github.com/schteppe/cannon.js
    Documentation: http://schteppe.github.io/cannon.js/docs/
    Lighter than Ammo.js
    More comfortable to implement than Ammo.js
    Mostly maintained by one developer
    Hasn't been updated for many years
    There is a maintained fork

Oimo.js
    Website: https://lo-th.github.io/Oimo.js/
    Git repository: https://github.com/lo-th/Oimo.js
    Documentation: http://lo-th.github.io/Oimo.js/docs.html
    Lighter than Ammo.js
    Easier to implement than Ammo.js
    Mostly maintained by one developer
    Hasn't been updated for 2 years
*/

//? Les forces
/*
There are many ways to apply forces to a Body:

    applyForce to apply a force to the Body from a specified point in space
    (not necessarily on the Body's surface) like the wind that pushes everything a little all the time,
    a small but sudden push on a domino or a greater sudden force to make an angry bird jump toward the enemy castle.

    applyImpulse is like applyForce but instead of adding to the force that will result in velocity changes,
    it applies directly to the velocity.

    applyLocalForce is the same as applyForce but the coordinates are local to the Body
    (meaning that 0, 0, 0 would be the center of the Body).

    applyLocalImpulse is the same as applyImpulse but the coordinates are local to the Body.
*/

//? Algo collision
/*
When testing the collisions between objects, a naive approach is testing every Body against every other Body.
While this is easy to do, it's costly in terms of performance.

That is where broadphase comes up. The broadphase is doing a rough sorting of the Bodies before testing them.
Imagine having two piles of boxes far from each other.
Why would you test the boxes from one pile against the boxes in the other pile?
They are too far to be colliding.

There are 3 broadphase algorithms available in Cannon.js:
 - NaiveBroadphase: Tests every Bodies against every other Bodies
 - GridBroadphase: Quadrilles the world and only tests Bodies against other Bodies in the same grid box or the neighbors' grid boxes.
 - SAPBroadphase (Sweep and prune broadphase): Tests Bodies on arbitrary axes during multiples steps.

The default broadphase is NaiveBroadphase, and I recommend you to switch to SAPBroadphase.
Using this broadphase can eventually generate bugs where a collision doesn't occur, but it's rare,
and it involves doing things like moving Bodies very fast.

---

Even if we use an improved broadphase algorithm, all the Body are tested,
even those not moving anymore. We can use a feature called sleep.

When the Body speed gets incredibly slow (at a point where you can't see it moving),
the Body can fall asleep and won't be tested unless a sufficient force is applied to it by code or if another Body hits it.
*/

//? Go Further
/*
Constraints

Constraints, as the name suggests, enable constraints between two bodies. We won't cover those in this lesson, but here's the list of constraints:

    HingeConstraint: acts like a door hinge.
    DistanceConstraint: forces the bodies to keep a distance between each other.
    LockConstraint: merges the bodies like if they were one piece.
    PointToPointConstraint: glues the bodies to a specific point.

 Classes, methods, properties and events

There are many classes, and each one with different methods, properties, and events. Try to browse through all of them at least once just to know that they exist. It might save you some time in your future projects.
Examples
The documentation isn't perfect. It would help if you spent some time in the demos and research to find out how to do things. Many people probably had the issues you might encounter. Don't hesitate to rely on the community.
Workers
Running the physics simulation takes time. The component of your computer doing the work is the CPU. When you run Three.js, Cannon.js, your code logic, etc. everything is done by the same thread in your CPU. That thread can quickly overload if there is too much to do (like too many objects in the physics simulation), resulting in a frame rate drop.
The right solution is to use workers. Workers let you put a part of your code in a different thread to spread the load. You can then send and receive data from that code. It can result in a considerable performance improvement.
The problem is that the code has to be distinctly separated. You can find a good and simple example here in the page source code.
Cannon-es
As we said earlier, Cannon.js hasn't been updated for years. Fortunately, some guys forked the repository and started working on updates. Thanks to them, we have access to a better and maintained version of Cannon.js:
    Git repository: https://github.com/pmndrs/cannon-es
    NPM page: https://www.npmjs.com/package/cannon-es

To use this version instead of the original, open the terminal in the project folder (or shut down the server), remove the previous cannon.js dependency with npm uninstall --save cannon.
As for cannon-es, you can install the latest version with npm install --save cannon-es and change the way you import Cannon.js in the code:

import * as CANNON from 'cannon-es'

Everything should be working just like before. You can check out the changes on the Git repository page.
The latest version should work as a drop-in replacement, but if you get an error, you can use a more specific version like the 0.20 (tested) by running npm install --save cannon-es@0.20.
Ammo.js

We used Cannon.js because the library is easy to implement and understand. One of its biggest competitors is Ammo.js. While it's harder to use and to implement in your project, here are some features that might be of interest to you:
    It's a portage of Bullet, a well known and well-oiled physics engine written in C++.
    It has WebAssembly (wasm) support. WebAssembly is a low-level language supported by most recent browsers. Because it's a low level, it has better performance.
    It's more popular, and you can find more examples of Three.js.
    It supports more features.

If you need the best performance or have particular features in your project, you probably should go for Ammo.js instead of Cannon.js.
*/



/**
 * Base
 */
// Canvas
const canvas = document.querySelector('canvas.webgl')

// Scene
const scene = new THREE.Scene()

const hitSound = new Audio('/sounds/hit.mp3') //? Some browsers like Chrome prevent sounds from playing unless the user has interacted with the page like clicking anywhere, so don't worry if you don't hear the first sounds.

const playHitSound = (collision) => {
    //? The first problem is that when we call hitSound.play() while the sound is playing, nothing happens because it is already playing. We can fix that by resetting the sound to 0 with the currentTime property:
    const impactStrength = collision.contact.getImpactVelocityAlongNormal()

    //? Bonus:
    //?   - Add more delay between each sound
    //?   - Play more random sound
    if (impactStrength > 1.5) {
        hitSound.volume = Math.random() / impactStrength
        hitSound.currentTime = 0
        hitSound.play()
    }
    hitSound.currentTime = 0
    hitSound.play()
}

/**
 * Textures
 */
const textureLoader = new THREE.TextureLoader()
const cubeTextureLoader = new THREE.CubeTextureLoader()

const environmentMapTexture = cubeTextureLoader.load([
    '/textures/environmentMaps/0/px.png',
    '/textures/environmentMaps/0/nx.png',
    '/textures/environmentMaps/0/py.png',
    '/textures/environmentMaps/0/ny.png',
    '/textures/environmentMaps/0/pz.png',
    '/textures/environmentMaps/0/nz.png'
])


/**
 * Physics
 */
const world = new CANNON.World()
world.gravity.set(0, -9.82, 0)
world.broadphase = new CANNON.SAPBroadphase(world) // ? optimisation perfo de la phyisque
world.allowSleep = true // ? optimisation perfo de la phyisque
//? sleepSpeedLimit peut être utilise pour mieux controler le mode sleep
const defaultMaterial = new CANNON.Material('default')
const defaultContactMaterial = new CANNON.ContactMaterial(
    defaultMaterial,
    defaultMaterial,
    {
        friction: 0.1,
        restitution: 0.7
    }
)
world.addContactMaterial(defaultContactMaterial)
world.defaultContactMaterial = defaultContactMaterial


// const sphereShape = new CANNON.Sphere(0.5)
// const sphereBody = new CANNON.Body({
//     mass: 1,
//     position: new CANNON.Vec3(0, 3, 0),
//     shape: sphereShape,
//     material: defaultMaterial
// })
// world.addBody(sphereBody)
// sphereBody.applyLocalForce(new CANNON.Vec3(150, 0, 0), new CANNON.Vec3(0, 0, 0))

const floorShape = new CANNON.Plane()
const floorBody = new CANNON.Body()
floorBody.material = defaultMaterial
floorBody.mass = 0
floorBody.addShape(floorShape)
floorBody.quaternion.setFromAxisAngle(new CANNON.Vec3(- 1, 0, 0), Math.PI * 0.5)
world.addBody(floorBody)

/**
 * Test sphere
 */
// const sphere = new THREE.Mesh(
//     new THREE.SphereGeometry(0.5, 32, 32),
//     new THREE.MeshStandardMaterial({
//         metalness: 0.3,
//         roughness: 0.4,
//         envMap: environmentMapTexture,
//         envMapIntensity: 0.5,
//     })
// )
// sphere.castShadow = true
// sphere.position.y = 0.5
// scene.add(sphere)

/**
 * Utils
*/

const objectsToUpdate = []

const sphereGeometry = new THREE.SphereGeometry(1, 20, 20)
const boxGeometry = new THREE.BoxGeometry(1, 1, 1)
const threeMaterial = new THREE.MeshStandardMaterial({
    metalness: 0.3,
    roughness: 0.4,
    envMap: environmentMapTexture,
    envMapIntensity: 0.5
})


const createSphere = (radius, position) => {
    // Three.js mesh
    const mesh = new THREE.Mesh(sphereGeometry, threeMaterial)
    mesh.scale.set(radius, radius, radius)
    mesh.castShadow = true
    mesh.position.copy(position)
    scene.add(mesh)

    // Cannon js body
    const shape = new CANNON.Sphere(radius)
    const body = new CANNON.Body({
        mass: 1,
        position: new CANNON.Vec3(0, 0, 0),
        shape: shape,
        material: defaultMaterial
    })
    body.position.copy(position)
    world.add(body)

    objectsToUpdate.push({
        mesh: mesh,
        body: body
    })
}

createSphere(0.5, { x: 0, y: 4, z: 0 })
createSphere(0.5, { x: 1, y: 2, z: 0 })
createSphere(0.5, { x: 0, y: 3, z: -2 })

const createBox = (width, height, depth, position) => {
    // Three.js mesh
    const mesh = new THREE.Mesh(boxGeometry, threeMaterial)
    mesh.scale.set(width, height, depth)
    mesh.castShadow = true
    mesh.position.copy(position)
    scene.add(mesh)

    // Cannon js body
    const shape = new CANNON.Box(new CANNON.Vec3(width * 0.5, height * 0.5, depth * 0.5))
    const body = new CANNON.Body({
        mass: 1,
        position: new CANNON.Vec3(0, 0, 0),
        shape: shape,
        material: defaultMaterial
    })
    body.position.copy(position)
    world.add(body)
    body.addEventListener('collide', playHitSound)

    objectsToUpdate.push({
        mesh: mesh,
        body: body
    })
}

createBox(1, 2, 1, { x: 1, y: 5, z: -4 })


/**
 * Floor
 */
const floor = new THREE.Mesh(
    new THREE.PlaneGeometry(10, 10),
    new THREE.MeshStandardMaterial({
        color: '#777777',
        metalness: 0.3,
        roughness: 0.4,
        envMap: environmentMapTexture,
        envMapIntensity: 0.5,
        side: THREE.DoubleSide
    })
)
floor.receiveShadow = true
floor.rotation.x = - Math.PI * 0.5
scene.add(floor)

/**
 * Lights
 */
const ambientLight = new THREE.AmbientLight(0xffffff, 0.7)
scene.add(ambientLight)

const directionalLight = new THREE.DirectionalLight(0xffffff, 0.2)
directionalLight.castShadow = true
directionalLight.shadow.mapSize.set(1024, 1024)
directionalLight.shadow.camera.far = 15
directionalLight.shadow.camera.left = - 7
directionalLight.shadow.camera.top = 7
directionalLight.shadow.camera.right = 7
directionalLight.shadow.camera.bottom = - 7
directionalLight.position.set(5, 5, 5)
scene.add(directionalLight)

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
camera.position.set(- 3, 3, 3)
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
renderer.shadowMap.enabled = true
renderer.shadowMap.type = THREE.PCFSoftShadowMap
renderer.setSize(sizes.width, sizes.height)
renderer.setPixelRatio(Math.min(window.devicePixelRatio, 2))

/**
 * Animate
 */
const clock = new THREE.Clock()
let oldElapsedTime = 0
const tick = () => {
    const elapsedTime = clock.getElapsedTime()
    const deltaTime = elapsedTime - oldElapsedTime
    oldElapsedTime = elapsedTime

    // sphereBody.applyForce(new CANNON.Vec3(- 0.5, 0, 0), sphereBody.position)

    world.step(1 / 60, deltaTime, 3)
    // sphere.position.copy(sphereBody.position)

    for (const object of objectsToUpdate) {
        object.mesh.quaternion.copy(object.body.quaternion)
        object.mesh.position.copy(object.body.position)
    }

    // Update controls
    controls.update()

    // Render
    renderer.render(scene, camera)

    // Call tick again on the next frame
    window.requestAnimationFrame(tick)
}

tick()