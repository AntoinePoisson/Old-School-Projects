import React, { useState, useEffect } from 'react';

import { Divider, Grid, IconButton, Typography } from '@material-ui/core';
import SettingsIcon from '@material-ui/icons/Settings';
import ButtonHandleCardPosition from '../../../Tools/ButtonHandleCardPosition';
import LoaderWidget from '../../../Tools/Loader';

import useStyles from '../../../../styles/WidgetTemplate';
import ModalSettingsMeteo from '../../../Modals/MeteoSetting';
import BodyMeteo from './Body/Meteo';

const WidgetMeteo = ({index, list, setList}) => {

    const classes = useStyles();

    const [modalSettings, setOpenModalSettings] = useState(false);
    const [isLoading, setLoader] = useState(true);
    const [isData, setData] = useState({});


    useEffect(() => {
        const myInit = {
            method: "POST",
            headers: new Headers({ "Content-Type": "application/json"}),
            mode: "cors",
            cache: "default",
            body: JSON.stringify({request: "http://api.openweathermap.org/data/2.5/weather?q=" + list[index].city + "&appid=XXXXXXXX_OPENWEATHERMAP_API_KEY_REDACTED_XXXXXXXX&units=metric"})
        };
        fetch(`http://localhost:8080/meteo`, myInit)
            .then(async res => {
                const result = await res.json()
                if (result.cod === 200) {
                    setData(result)
                    setLoader(false);
                } else {
                    console.error(result)
                }
            })
            .catch((error) => {
                console.error(error)
            })
    // eslint-disable-next-line react-hooks/exhaustive-deps
    }, [list[index]]);

    return (
        <Grid className={classes.root}>
            <Grid container className={classes.bar}>
                <Grid item xs={10} style={{display: "flex"}}>
                    <Typography className={classes.title} variant="h5" component="h5" style={{color: list[index].color}}>
                        { list[index].title }
                    </Typography>
                </Grid>
                <Grid item xs={2}  style={{display: "flex", justifyContent: "flex-end"}}>
                    <ButtonHandleCardPosition index={index} list={list} setList={setList} />
                    <IconButton size="medium" onClick={() => setOpenModalSettings(true)}>
                        <SettingsIcon />
                    </IconButton>
                </Grid>
            </Grid>
            <Divider orientation="horizontal" style={{backgroundColor: "black"}} />
            <Grid className={classes.body}>
                { isLoading ?
                    <LoaderWidget color={list[index].color} />
                :
                    <BodyMeteo data={isData} />
                }
            </Grid>
            <ModalSettingsMeteo
                open={modalSettings}
                setOpen={() => setOpenModalSettings(false)}
                index={index}
                list={list}
                setList={setList} />
        </Grid>
    );
};

export default WidgetMeteo;