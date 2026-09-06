import React from 'react';

import { Oval } from '@agney/react-loading';

import { Grow } from '@material-ui/core';


const LoaderWidget = ({color}) => {
    return (
        <Grow in={true} {...({ timeout: 1000 })}>
            <div style={{display: "flex", position: "relative", justifyContent: "center", height: "inherit"}}>
                <Oval width={75} style={{color: "gray"}}/>
            </div>
        </Grow>
    );
};

export default LoaderWidget;
