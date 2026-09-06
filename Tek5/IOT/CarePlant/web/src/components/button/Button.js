import React from 'react';

import './Button.sass';

const Button = ({ onClick, value, className }) => {


    return (
        <button
            className={!className ? "button" : className}
            onClick={() => onClick()}>
            {value}
        </button>
    );
};

export default Button;
