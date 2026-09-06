import React from 'react';

import './FieldInput.sass';

const Input = ({ label, placeholder, value, onChange }) => {

    return (
        <div className='divinput'>
            { label && <p className='label'>{label}</p> }
            <input
                className="input"
                placeholder={placeholder}
                value={value}
                type={"text"}
                onChange={(event) => onChange(event.target.value)} />
        </div>
    );
};

export default Input;
