import React, { Fragment, useContext, useEffect, useState } from 'react';

import PlayArrowRoundedIcon from '@material-ui/icons/PlayArrowRounded';
import { Divider, Grid, Grow, IconButton, Paper, Typography } from '@material-ui/core';
import AddIcon from '@material-ui/icons/Add';

import useStyles from '../../../styles/DashboardAdding';
import ModalSettingsImgur from '../../Modals/AddImgur';
import ModalSettingsImgurProfile from '../../Modals/AddImgurProfile';
import ModalSettingsMeteo from '../../Modals/AddMeteo';
import ModalSettingsApex from '../../Modals/AddApex';
import ModalSettingsGithubIssue from '../../Modals/AddGithubIssue';
import ModalSettingsGithubAction from '../../Modals/AddGithubAction';
import ModalSettingsYoutube from '../../Modals/AddYoutubeChannel';
import ModalSettingsYoutubeSubscriber from '../../Modals/AddYoutubeSubsriber';
import { BallTriangle } from '@agney/react-loading';
import DataContext from '../../../contexts/dataContext';
import MySnackBar from '../../Tools/SnackBar';
import ModalSettingsImgurPostImage from '../../Modals/AddImgurPostImage';
import ModalSettingsTwitchProfile from '../../Modals/AddTwitchProfile';


const DashboardAdding = () => {

    const classes = useStyles();

    const [dataState, ] = useContext(DataContext);
    const [list, ] = useState(dataState.About);
    const [loading, ] = useState(false);
    const [addElement, setAddElement] = useState({type: "", clicked: false, data: {}});
    const [snackbar, setSnackbar] = useState({message: "", type: "", recall: 0})

    useEffect(() => {
        if (Object.entries(addElement.data).length === 0 || addElement.clicked === false || addElement.type === "" || addElement.data === {})
            return;
        const myInit = {
            method: "POST",
            headers: new Headers({ "Content-Type": "application/json" }),
            mode: "cors",
            body: JSON.stringify({token: dataState.Token}),
            cache: "default"
        };
        fetch(`http://localhost:8080/dashboard/get`, myInit)
        .then(async res => {
            const result = await res.json()
            if (result.error) {
                setSnackbar({ message: "Faluire Adding Widget", type: "error", recall: snackbar.recall + 1 });
            } else {
                const myInit_ = {
                    method: "POST",
                    headers: new Headers({ "Content-Type": "application/json" }),
                    mode: "cors",
                    body: JSON.stringify({token: dataState.Token, config: JSON.stringify(result.result.dashboard !== "" ? [addElement.data, ...JSON.parse(result.result.dashboard)] : [addElement.data])}),
                    cache: "default"
                };
                fetch(`http://localhost:8080/dashboard/save`, myInit_)
                .then(async r => {
                    const re = await r.json()
                    if (re.error) {
                        setAddElement({ type: "", clicked: false, data: {} })
                        setSnackbar({ message: "Faluire Adding Widget", type: "error", recall: snackbar.recall + 1 });
                    } else {
                        setSnackbar({ message: "Adding Widget", type: "success", recall: snackbar.recall + 1 });
                        setAddElement({ type: "", clicked: false, data: {} })
                    }
                })
                .catch((error) => {
                    setSnackbar({ message: "Faluire Adding Widget", type: "error", recall: snackbar.recall + 1 });
                    setAddElement({ type: "", clicked: false, data: {} })
                })
            }
        })
        .catch((error) => {
            setSnackbar({ message: "Faluire Adding Widget", type: "error", recall: snackbar.recall + 1 });
        })
    // eslint-disable-next-line react-hooks/exhaustive-deps
    }, [addElement.data]);

    const selectWidget = () => {
        if (addElement.clicked === false)
            return;
        if (addElement.type === "")
            setAddElement({ type: "", clicked: false, data: {} })
        switch (addElement.type) {
            case "Twitch-Search Streammer": return (<ModalSettingsTwitchProfile addElement={addElement} setData={(el) => setAddElement(el)} />)
            case "Imgur-Gallery": return (<ModalSettingsImgur addElement={addElement} setData={(el) => setAddElement(el)} />)
            case "Imgur-Post Image": return (<ModalSettingsImgurPostImage addElement={addElement} setData={(el) => setAddElement(el)} />)
            case "Meteo-Meteo": return (<ModalSettingsMeteo addElement={addElement} setData={(el) => setAddElement(el)} />)
            case "Apex-Apex": return (<ModalSettingsApex addElement={addElement} setData={(el) => setAddElement(el)} />)
            case "Imgur-Profile": return (<ModalSettingsImgurProfile addElement={addElement} setData={(el) => setAddElement(el)} />)
            case "Github-Issue": return (<ModalSettingsGithubIssue addElement={addElement} setData={(el) => setAddElement(el)} />)
            case "Github-Action": return (<ModalSettingsGithubAction addElement={addElement} setData={(el) => setAddElement(el)} />)
            case "Youtube-Channel": return (<ModalSettingsYoutube addElement={addElement} setData={(el) => setAddElement(el)} />)
            case "Youtube-Subscriber": return (<ModalSettingsYoutubeSubscriber addElement={addElement} setData={(el) => setAddElement(el)} />)
            default: return (<div />)
        }
    };

    const checkServiceIsUp = (name) => {
        if (!name || name === undefined || name.length === 0)
            return (true);
        switch (name) {
            case "Imgur":
                if (dataState.TokenServices && dataState.TokenServices.Imgur && dataState.TokenServices.Imgur.length !== 0)
                    return (true);
                return (false);
            case "GitHub":
                if (dataState.TokenServices && dataState.TokenServices.Github && dataState.TokenServices.Github.length !== 0)
                    return (true);
                return (false);
            case "Github":
                if (dataState.TokenServices && dataState.TokenServices.Github && dataState.TokenServices.Github.length !== 0)
                    return (true);
                return (false);
            case "Twitch":
                if (dataState.TokenServices && dataState.TokenServices.Twitch && dataState.TokenServices.Twitch.length !== 0)
                    return (true);
                return (false);
            case "Youtube":
                if (dataState.TokenServices && dataState.TokenServices.Google && dataState.TokenServices.Google.length !== 0)
                    return (true);
                return (false);
            case "Google":
                if (dataState.TokenServices && dataState.TokenServices.Google && dataState.TokenServices.Google.length !== 0)
                    return (true);
                return (false);
            default: return (true);
        }
    };

    if (loading)
        return (
            <div className={classes.root}>
                <Typography variant="h4" component="h4">
                    <PlayArrowRoundedIcon style={{ marginLeft: "20px", fontSize: "26px" }}/> Adding Widget
                </Typography>
                <Grid className={classes.noWidget}>
                    <BallTriangle width={125} style={{color: "white" }} />
                </Grid>
            </div>
        );

    return (
        <div className={classes.root}>
            <Typography variant="h4" component="h4">
                <PlayArrowRoundedIcon style={{ marginLeft: "20px", fontSize: "26px" }}/> Adding Widget
            </Typography>
            <Grid container className={classes.Container}>
                { list.server.services.map((service, index) => (
                    <Grid item key={`${index}-widget-${service.name}`} xs={(service.size)} className={!checkServiceIsUp(service.need_token) ? classes.disablePaper : classes.useless}>
                        <Fragment>
                            <Grow in={true} {...({ timeout: 1000 })}>
                                <Paper className={classes.Wrapper} elevation={3}>
                                    <Grid style={{display: "flex"}}>
                                        <Typography className={classes.title} variant="h5" component="h5">
                                            { service.name }
                                        </Typography>
                                    </Grid>
                                    <Divider orientation="horizontal" style={!checkServiceIsUp(service.need_token) ? {backgroundColor: "red"} : {backgroundColor: "black"}} />
                                    <div className={classes.body}>
                                        { service.widgets.map((widget, i) => (
                                            <Paper key={`${i}-${index}`} className={(!checkServiceIsUp(service.need_token) || !checkServiceIsUp(widget.need_service)) ? classes.disableWidget : classes.widget} elevation={2}>
                                                <Typography className={classes.textItem} variant="h6" component="h6">
                                                    { widget.name }
                                                </Typography>
                                                <div className={classes.buttonItem}>
                                                    <IconButton onClick={() => setAddElement({type: `${service.name}-${widget.name}`, clicked: true, data: {}})} disabled={(!checkServiceIsUp(service.need_token) || !checkServiceIsUp(widget.need_service))}>
                                                        <AddIcon style={(!checkServiceIsUp(service.need_token) || !checkServiceIsUp(widget.need_service)) ? {color: "red"} : {color: "black"}} />
                                                    </IconButton>
                                                </div>
                                                <Typography className={classes.textItem} variant="body2" component="h6">
                                                    { widget.description }
                                                </Typography>
                                            </Paper>
                                          ))
                                        }
                                    </div>
                                </Paper>
                            </Grow>
                        </Fragment>
                    </Grid>
                  ))
                }
                { selectWidget() }
            </Grid>
            <MySnackBar message={snackbar.message} type={snackbar.type} recall={snackbar.recall} />
        </div>
    );
};

export default DashboardAdding;