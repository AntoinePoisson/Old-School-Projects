import React from 'react';

import { Grid } from '@material-ui/core';


const BodyTemplate = ({props}) => {

    return (
        <Grid>
            <p>
                { props }
            </p>
        </Grid>
    );
};

export default BodyTemplate;