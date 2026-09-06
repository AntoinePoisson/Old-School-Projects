import React, { useState, useEffect, useContext } from 'react';

import { Divider, Grid, IconButton, Typography } from '@material-ui/core';
import SettingsIcon from '@material-ui/icons/Settings';
import ButtonHandleCardPosition from '../../../Tools/ButtonHandleCardPosition';
import LoaderWidget from '../../../Tools/Loader';

import useStyles from '../../../../styles/WidgetTemplate';
import ModalSettingsYoutubeSubscribers from '../../../Modals/YoutubeSubscriberSettings';
import BodyYoutubeSubscriber from './Body/YoutubeSubscriber';
import DataContext from '../../../../contexts/dataContext';

const WidgetYoutubeSubscriber = ({index, list, setList}) => {

    const classes = useStyles();

    const [modalSettings, setOpenModalSettings] = useState(false);
    const [isLoading, setLoader] = useState(true);
    const [isData, setData] = useState({});
    const [dataState] = useContext(DataContext);

    useEffect(() => {
        const myInit = {
            method: "POST",
            headers: new Headers({ "Content-Type": "application/json"}),
            mode: "cors",
            cache: "default",
            body: JSON.stringify({request: `https://youtube.googleapis.com/youtube/v3/subscriptions?part=subscriberSnippet${list[index].time ? ",snippet" : ""}&myRecentSubscribers=true&key=XXXXXXXX_GOOGLE_API_KEY_REDACTED_XXXXXXXX`, bearer: dataState.TokenServices.Google})
        };
        fetch(`http://localhost:8080/ytb`, myInit)
            .then(async res => {
                const result = await res.json()
                if (result.items) {
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
        <Grid className={classes.root} style={{ margin: '5px'}}>
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
                    <BodyYoutubeSubscriber data={ isData } />
                }
            </Grid>
            <ModalSettingsYoutubeSubscribers
                open={modalSettings}
                setOpen={() => setOpenModalSettings(false)}
                index={index}
                list={list}
                setList={setList} />
        </Grid>
    );
};

export default WidgetYoutubeSubscriber;