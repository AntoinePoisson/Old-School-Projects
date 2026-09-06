precision mediump float;
        //? highp
        //? mediump
        //? lowp
// varying float vRandom;
varying float vElevation;
uniform vec3 uColor;
uniform sampler2D uTexture;

varying vec2 vUv;

void main()
{
    vec4 textureColor = texture2D(uTexture, vUv);
    textureColor.rgb *= vElevation * 2.0 + 0.6;
    gl_FragColor = textureColor;
    // gl_FragColor = vec4(0.5, 0.0, 1.0, 0.8);
    // gl_FragColor = vec4(uColor, 0.8);
}