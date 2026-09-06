import React, { useState, useEffect } from 'react';

import { Divider, Grid, IconButton, Typography } from '@material-ui/core';
import SettingsIcon from '@material-ui/icons/Settings';
import ButtonHandleCardPosition from '../../../Tools/ButtonHandleCardPosition';
import LoaderWidget from '../../../Tools/Loader';

import useStyles from '../../../../styles/WidgetTemplate';
import ModalSettingsImgurProfile from '../../../Modals/ImgurProfileSettings';
import BodyImgurProfile from './Body/ImgurProfile';

const WidgetImfurProfile = ({index, list, setList}) => {

    const classes = useStyles();

    const [modalSettings, setOpenModalSettings] = useState(false);
    const [isLoading, setLoader] = useState(true);
    const [isData, setData] = useState({});
    const [isProfile, setProfile] = useState({});

    const loadProfileInfo = () => {
        const myInit = {
            method: "GET",
            headers: new Headers({ "Content-Type": "application/json", "Authorization": "Bearer XXXXXXXX_IMGUR_ACCESS_TOKEN_REDACTED_XXXXXXXX"}),
            mode: "cors",
            cache: "default",
        };
        fetch(`https://api.imgur.com/3/account/me/`, myInit)
        .then(async res => {
                const result = await res.json()
                if (result.success === true) {
                    setProfile(result.data)
                    console.log("OK imgur profile data", Object.keys(isData).length)
                    setLoader(false)
                } else {
                    console.error(result)
                }
            })
            .catch((error) => {
                console.error(error)
            })
    // eslint-disable-next-line react-hooks/exhaustive-deps
    };

    useEffect(() => {
        const myInit = {
            method: "GET",
            headers: new Headers({ "Content-Type": "application/json", "Authorization": "Bearer XXXXXXXX_IMGUR_ACCESS_TOKEN_REDACTED_XXXXXXXX"}),
            mode: "cors",
            cache: "default",
        };
        fetch(`https://api.imgur.com/3/account/me/images`, myInit)
            .then(async res => {
                const result = await res.json()
                if (result.success === true) {
                    setData(result.data)
                    console.log("OK imgur profile image", Object.keys(isProfile).length)
                    if (list[index].info) {
                        loadProfileInfo()
                    } else {
                        setLoader(false)
                    }
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
                    <BodyImgurProfile data={isData} profile={isProfile} />
                }
            </Grid>
            <ModalSettingsImgurProfile
                open={modalSettings}
                setOpen={() => setOpenModalSettings(false)}
                index={index}
                list={list}
                setList={setList} />
        </Grid>
    );
};

export default WidgetImfurProfile;