import React, { useState, useEffect, useContext } from 'react';

import { Divider, Grid, IconButton, Typography } from '@material-ui/core';
import SettingsIcon from '@material-ui/icons/Settings';
import ButtonHandleCardPosition from '../../../Tools/ButtonHandleCardPosition';
import useStyles from '../../../../styles/WidgetTemplate';
import DataContext from '../../../../contexts/dataContext';
import ModalSettingsTwitchProfile from '../../../Modals/TwitchProfileSettings';
import BodyTwitchProfile from './Body/BodyTwitchProfile';
import Momo from '../../../../resources/images/momo.png'
import '../../../../styles/Spinner.css'


const WidgetTwitchProfile = ({index, list, setList}) => {

    const classes = useStyles();

    const [modalSettings, setOpenModalSettings] = useState(false);
    const [isLoading, setLoader] = useState(true);
    const [input, setInput] = useState({name: "", load: false, data: []});
    const [dataState, ] = useContext(DataContext);

    useEffect(() => {
        if (input.name.length === 0)
            setLoader(true);
        if (input.name.length === 0 || input.load === true)
            return;
        const myInit = {
            method: "POST",
            headers: new Headers({ "Content-Type": "application/json"}),
            mode: "cors",
            cache: "default",
            body: JSON.stringify({request: `https://api.twitch.tv/helix/search/channels?query=${input.name}`, oauth: `${dataState.TokenServices.Twitch}`, client: "mw2o23npn444en9kgkdarmkurmpfoa"})
        };
        fetch(`http://localhost:8080/twitch/tricks`, myInit)
            .then(async res => {
                const result = await res.json()
                console.log(result)
                setInput({...input, data: result.data, load: true})
                setLoader(false);
            })
            .catch((error) => {
                console.error(error)
            })
    // eslint-disable-next-line react-hooks/exhaustive-deps
    }, [input]);

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
                { (isLoading || !input.data || input.data.length === 0) ?
                    <img src={Momo} alt="" style={{height: "212px", animation: `spin 2s linear infinite`, margin: "auto", display: "flex", overflowY: 'hidden'}} />
                :
                    <BodyTwitchProfile list={input.data} />
                }
            </Grid>
            <ModalSettingsTwitchProfile
                open={modalSettings}
                setOpen={() => setOpenModalSettings(false)}
                setInput={(el) => setInput(el)}
                input={input}/>
        </Grid>
    );
};

export default WidgetTwitchProfile;