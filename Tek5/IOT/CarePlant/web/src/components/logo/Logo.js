import React from 'react';
import LogoApp from '../../resources/logos/logo.png'

const Logo = ({ width, className }) => {

    return (
        <img className={className} src={LogoApp} alt="logo" width={width} />
    );
};

export default Logo;
