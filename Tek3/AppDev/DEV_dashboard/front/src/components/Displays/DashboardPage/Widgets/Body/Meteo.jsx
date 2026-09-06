import React from 'react';

import { Grid } from '@material-ui/core';
import bg from './img/bg_meteo.jpg'


const BodyMeteo = ({data}) => {
    return (
        <Grid style={{backgroundImage: `url(${bg})`, borderRadius: "5px", height: "238px"}}>
            <Grid container direction="row">
                <img src={"http://openweathermap.org/img/wn/" + data.weather[0].icon + "@2x.png"} alt=""/>
                <p style={{fontSize: "30px"}}>{data.main.temp}</p>
            </Grid>
            <p style={{marginLeft: "20px", fontSize: "20px", marginTop: "5px"}}>{data.weather[0].description}</p>
            <p style={{marginLeft: "20px", fontSize: "20px", marginTop: "5px"}}>{data.name}</p>
            <Grid style={{marginLeft: "20px"}} container direction="row">
                <p style={{fontSize: "20px", margin: "5px"}}>L: {data.main.temp_min}</p>
                <p style={{marginLeft: "20px", fontSize: "20px", margin: "5px"}}>H: {data.main.temp_max}</p>
            </Grid>
        </Grid>
    );
};

export default BodyMeteo;