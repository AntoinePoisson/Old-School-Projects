import React, { Fragment, useState, useEffect, useContext } from 'react';

import { Button, Grid, Grow, Paper, Typography } from '@material-ui/core';
import PlayArrowRoundedIcon from '@material-ui/icons/PlayArrowRounded';

import useStyles from '../../../styles/DashboardHome';
import WidgetTemplate from './Widgets/Template';
import WidgetImgur from './Widgets/Imgur';
import WidgetGithubIssue from './Widgets/GithubIssue';
import { BallTriangle } from '@agney/react-loading';
import { Redirect } from "react-router-dom";
import WidgetMeteo from './Widgets/Meteo';
import WidgetYoutubeChannel from './Widgets/YoutubeChannel';
import WidgetYoutubeSubscriber from './Widgets/YoutubeSubscriber';
import WidgetImgurProfile from './Widgets/ImgurProfile';
import WidgetApex from './Widgets/Apex'
import WidgetGithubAction from './Widgets/GithubAction';
import DataContext from '../../../contexts/dataContext';
import MySnackBar from '../../Tools/SnackBar';
import useInterval from '../../Tools/UseInterval';
import WidgetImagePostImage from './Widgets/ImgurPostImage';
import WidgetTwitchProfile from './Widgets/TwitchProfile';


const DashboardHome = () => {

    const classes = useStyles();

    const [list, setterList] = useState([]);
    const [goAdding, setGoAdding] = useState(false);
    const [loading, setLoading] = useState(true);
    const [dataState, ] = useContext(DataContext);
    const [snackbar, setSnackbar] = useState({message: "", type: "", recall: 0})
    const [randKey, setRandKey] = useState(Math.random());

    useInterval(() => {
        if (list.length !== 0) {
            console.log("RELOAD !");
            setRandKey(Math.random())
            setSnackbar({ message: "Reloading Widget", type: "info", recall: snackbar.recall + 1 });
        }
    }, 60000);

    useEffect(() => {
        if ((loading === false) || (loading === true && goAdding === true))
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
                setSnackbar({ message: "Failure Get Widget", type: "error", recall: snackbar.recall + 1 });
            } else {
                if (result.result.dashboard === ""  || JSON.parse(result.result.dashboard).length === 0 || !result.result.dashboard || result.result.dashboard === undefined ||
                    result.result.dashboard === [] || result.result.dashboard === "" ||
                    result.result.dashboard.length === 0 || Object.entries(result.result.dashboard).length === 0) {
                    setterList([]);
                    setSnackbar({ message: "No Widget", type: "warning", recall: snackbar.recall + 1 });
                } else {
                    setterList(JSON.parse(result.result.dashboard));
                }
                setLoading(false);
            }
        })
        .catch((error) => {
            setSnackbar({ message: "Failure Get Widget", type: "error", recall: snackbar.recall + 1 });
        })
    // eslint-disable-next-line react-hooks/exhaustive-deps
    }, [loading]);

    useEffect(() => {
        if ((loading === true) || (loading === true && goAdding === true))
            return;
        const myInit = {
            method: "POST",
            headers: new Headers({ "Content-Type": "application/json" }),
            mode: "cors",
            body: JSON.stringify({token: dataState.Token, config: JSON.stringify(list)}),
            cache: "default"
        };
        fetch(`http://localhost:8080/dashboard/save`, myInit)
        .then(async res => {
            const result = await res.json()
            if (result.error) {
                setSnackbar({ message: "Failure Save Widget", type: "error", recall: snackbar.recall + 1 });
            }
        })
        .catch((error) => {
            setSnackbar({ message: "Failure Save Widget", type: "error", recall: snackbar.recall + 1 });
        })
    // eslint-disable-next-line react-hooks/exhaustive-deps
    }, [list]);

    const selectWidget = (type, index, list, setList) => {
        switch(type) {
            case "TwitchProfile": return (<WidgetTwitchProfile index={index} list={list} setList={setList} />)
            case "Template": return (<WidgetTemplate index={index} list={list} setList={setList} />)
            case "ImgurPostImage": return (<WidgetImagePostImage index={index} list={list} setList={setList} />)
            case "Imgur": return (<WidgetImgur index={index} list={list} setList={setList} />)
            case "GithubIssue": return (<WidgetGithubIssue index={index} list={list} setList={setList} />)
            case "GithubAction": return (<WidgetGithubAction index={index} list={list} setList={setList} />)
            case "Meteo": return (<WidgetMeteo index={index} list={list} setList={setList} />)
            case "YoutubeChannel": return (<WidgetYoutubeChannel index={index} list={list} setList={setList} />)
            case "YoutubeSubscriber": return (<WidgetYoutubeSubscriber index={index} list={list} setList={setList} />)
            case "Apex": return (<WidgetApex index={index} list={list} setList={setList} />)
            case "ImgurProfile": return (<WidgetImgurProfile index={index} list={list} setList={setList} />)
            default: return (<WidgetTemplate index={index} list={list} setList={setList} />)
        }
    };

    if (goAdding)
        return ( <Redirect to="/dashboard/adding" /> );

    if (loading)
        return (
            <div className={classes.root}>
                <Typography variant="h4" component="h4">
                    <PlayArrowRoundedIcon style={{ marginLeft: "20px", fontSize: "26px" }}/> Adding Widget
                </Typography>
                <Grid className={classes.noWidget}>
                    <BallTriangle width={125} style={{color: "white" }} />
                </Grid>
                <MySnackBar message={snackbar.message} type={snackbar.type} recall={snackbar.recall} />
            </div>
        );

    if (list.length === 0) {
        return (
            <div className={classes.root}>
                <Typography variant="h4" component="h4">
                    <PlayArrowRoundedIcon style={{ marginLeft: "20px", fontSize: "26px" }}/> Dashboard
                </Typography>
                <Grid className={classes.noWidget}>
                    <BallTriangle width={125} style={{color: "white", marginBottom: "150px"}} />
                    <Typography variant="h5" component="h5" style={{marginBottom: "20px"}}>
                        You don't have any Widget
                    </Typography>
                    <Button variant="contained" color="primary" onClick={() => {setLoading(true); setGoAdding(true);}}>
                        Add Widget
                    </Button>
                </Grid>
                <MySnackBar message={snackbar.message} type={snackbar.type} recall={snackbar.recall} />
            </div>
        );
    }

    return (
        <div className={classes.root}>
            <Typography variant="h4" component="h4">
                <PlayArrowRoundedIcon style={{ marginLeft: "20px", fontSize: "26px" }}/> Dashboard
            </Typography>
            <Grid container className={classes.Container}>
                { list && list.length && list.map((element, index) => (
                    <Grid item key={`${index}-widget-${element.title}-${randKey}`} xs={element.size}>
                        <Fragment>
                            <Grow in={true} {...({ timeout: 1000 })}>
                                <Paper className={classes.Wrapper} elevation={3}>
                                    { selectWidget(element.type, index, list, (el) => setterList(el)) }
                                </Paper>
                            </Grow>
                        </Fragment>
                    </Grid>
                  ))
                }
            </Grid>
            <MySnackBar message={snackbar.message} type={snackbar.type} recall={snackbar.recall} />
        </div>
    );
};

export default DashboardHome;