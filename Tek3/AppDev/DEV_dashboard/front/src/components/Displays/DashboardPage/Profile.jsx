import React, { useContext, useEffect, useState } from 'react';

import PlayArrowRoundedIcon from '@material-ui/icons/PlayArrowRounded';

import { Grid, Typography } from '@material-ui/core';

import GitHubLogin from 'react-github-login';
import { MicrosoftLogin } from 'react-microsoft-login';
import { GoogleLogin } from 'react-google-login';
import { BallTriangle } from '@agney/react-loading';
import useStyles from '../../../styles/DashboardProfile';
import GithubIcon from '../../../resources/images/github.png';
import ImgurIcon from '../../../resources/images/imgur.png';
import TwitchIcon from '../../../resources/images/twitch.png';
import DataContext from '../../../contexts/dataContext';
import MySnackBar from '../../Tools/SnackBar';
import OAuth2Login from 'react-simple-oauth2-login';
import carapute from './img/carapute.gif'



function DashboardProfile() {

    const classes = useStyles();

    const [oauthGitHub, setOauthGitHub] = useState(undefined);
    const [oauthImgur, setOauthImgur] = useState(undefined);
    const [oauthTwitch, setOauthTwitch] = useState(undefined);
    const [oauthMicrosoft, setOauthMicrosoft] = useState(undefined);
    const [oauthGoogle, setOauthGoogle] = useState(undefined);
    const [dataState, dataDispatch] = useContext(DataContext);
    const [snackbar, setSnackbar] = useState({message: "", type: "", recall: 0})

    useEffect(() => {
        if (!oauthGitHub || oauthGitHub === undefined || !oauthGitHub.code.length)
            return;
        const myInit_ = {
            method: "POST",
            headers: new Headers({ "Content-Type": "application/json" }),
            mode: "cors",
            body: JSON.stringify({request: `https://github.com/login/oauth/access_token?client_id=4d2873338bb03f9ec247&client_secret=XXXXXXXX_GITHUB_CLIENT_SECRET_REDACTED_XXXXXXXX&code=${oauthGitHub.code}`}),
            cache: "default"
        };
        fetch("http://localhost:8080/meteo", myInit_)
            .then(async (res) => {
                const result = await res.text();
                if (result.error) {
                    setSnackbar({ message: "Failure with GitHub", type: "error", recall: snackbar.recall + 1 });
                } else {
                    const myInit = {
                        method: "POST",
                        headers: new Headers({ "Content-Type": "application/json" }),
                        mode: "cors",
                        body: JSON.stringify({token: dataState.Token, tokens: JSON.stringify({...dataState.TokenServices, Github: result.split("&")[0].split("=")[1]})}),
                        cache: "default"
                    };
                    fetch("http://localhost:8080/token/save", myInit)
                        .then(async (r) => {
                            const re = await r.text();
                            if (re.error) {
                                setSnackbar({ message: "Failure with GitHub", type: "error", recall: snackbar.recall + 1 });
                            } else {
                                setSnackbar({ message: "Login with GitHub", type: "success", recall: snackbar.recall + 1 });
                                dataDispatch({ type: "SET_TOKEN_SERVICES", TokenServices: {...dataState.TokenServices, Github: result.split("&")[0].split("=")[1]}})
                            }
                            setOauthGitHub(undefined);
                        })
                        .catch((error) => {
                            setSnackbar({ message: "Failure with GitHub", type: "error", recall: snackbar.recall + 1 });
                            setOauthGitHub(undefined);
                        });
                }
            })
            .catch((error) => {
                setSnackbar({ message: "Failure with GitHub", type: "error", recall: snackbar.recall + 1 });
                setOauthGitHub(undefined);
            });
    // eslint-disable-next-line react-hooks/exhaustive-deps
    }, [oauthGitHub]);

    useEffect(() => {
        if (!oauthImgur || oauthImgur === undefined)
            return;
        console.log("Data:", oauthImgur);
        const myInit_ = {
            method: "POST",
            headers: new Headers({ "Content-Type": "application/json" }),
            mode: "cors",
            body: JSON.stringify({token: dataState.Token, tokens: JSON.stringify({...dataState.TokenServices, Imgur: oauthImgur.access_token})}),
            cache: "default"
        };
        fetch(`http://localhost:8080/token/save`, myInit_)
            .then(async (res) => {
                const result = await res.json();
                if (result.error) {
                    setSnackbar({ message: "Error Login with Imgur", type: "error", recall: snackbar.recall + 1 });
                } else {
                    setSnackbar({ message: "Login with Imgur", type: "success", recall: snackbar.recall + 1 });
                    dataDispatch({ type: "SET_TOKEN_SERVICES", TokenServices: {...dataState.TokenServices, Imgur: oauthImgur.access_token}})
                }
                setOauthImgur(undefined)
            })
            .catch((error) => {
                setSnackbar({ message: "Error Login with Imgur", type: "error", recall: snackbar.recall + 1 });
                setOauthImgur(undefined)
            });
    // eslint-disable-next-line react-hooks/exhaustive-deps
    }, [oauthImgur]);

    useEffect(() => {
        if (!oauthMicrosoft || oauthMicrosoft === undefined)
            return;
        console.log("Data:", oauthMicrosoft);
        setOauthMicrosoft(undefined);
        setSnackbar({ message: "Login with Microsoft", type: "success", recall: snackbar.recall + 1 });
    // eslint-disable-next-line react-hooks/exhaustive-deps
    }, [oauthMicrosoft]);

    useEffect(() => {
        if (!oauthGoogle || oauthGoogle === undefined)
            return;
        const myInit_ = {
            method: "POST",
            headers: new Headers({ "Content-Type": "application/json" }),
            mode: "cors",
            body: JSON.stringify({token: dataState.Token, tokens: JSON.stringify({...dataState.TokenServices, Google: oauthGoogle.accessToken})}),
            cache: "default"
        };
        fetch(`http://localhost:8080/token/save`, myInit_)
            .then(async (res) => {
                const result = await res.json();
                if (result.error) {
                    setSnackbar({ message: "Error Login with Google", type: "error", recall: snackbar.recall + 1 });
                } else {
                    setSnackbar({ message: "Login with Google", type: "success", recall: snackbar.recall + 1 });
                    dataDispatch({ type: "SET_TOKEN_SERVICES", TokenServices: {...dataState.TokenServices, Google: oauthGoogle.accessToken}})
                }
                setOauthGoogle(undefined);
            })
            .catch((error) => {
                setSnackbar({ message: "Error Login with Google", type: "error", recall: snackbar.recall + 1 });
                setOauthGoogle(undefined);
            });
    // eslint-disable-next-line react-hooks/exhaustive-deps
    }, [oauthGoogle]);

    useEffect(() => {
        if (!oauthTwitch || oauthTwitch === undefined)
            return;
        const myInit_ = {
            method: "POST",
            headers: new Headers({ "Content-Type": "application/json" }),
            mode: "cors",
            body: JSON.stringify({token: dataState.Token, tokens: JSON.stringify({...dataState.TokenServices, Twitch: oauthTwitch.access_token})}),
            cache: "default"
        };
        fetch(`http://localhost:8080/token/save`, myInit_)
            .then(async (res) => {
                const result = await res.json();
                if (result.error) {
                    setSnackbar({ message: "Error Login with Twitch", type: "error", recall: snackbar.recall + 1 });
                } else {
                    setSnackbar({ message: "Login with Twitch", type: "success", recall: snackbar.recall + 1 });
                    dataDispatch({ type: "SET_TOKEN_SERVICES", TokenServices: {...dataState.TokenServices, Twitch: oauthTwitch.access_token}})
                }
                setOauthTwitch(undefined);
            })
            .catch((error) => {
                setSnackbar({ message: "Error Login with Twitch", type: "error", recall: snackbar.recall + 1 });
                setOauthTwitch(undefined);
            });
    // eslint-disable-next-line react-hooks/exhaustive-deps
    }, [oauthTwitch]);



    if (oauthGitHub || oauthMicrosoft || oauthGoogle || oauthImgur || oauthTwitch)
        return (
            <div className={classes.root}>
                <Typography variant="h4" component="h4">
                    <PlayArrowRoundedIcon style={{ marginLeft: "20px", fontSize: "26px" }}/> Profile
                </Typography>
                <Grid className={classes.noWidget}>
                    <BallTriangle width={125} style={{color: "white" }} />
                </Grid>
            </div>
        );

    return (
        <div className={classes.root}>
            <Typography variant="h4" component="h4">
                <PlayArrowRoundedIcon style={{ marginLeft: "20px", fontSize: "26px" }} /> Profile
            </Typography>
            <Grid container className={classes.Container}>
                <div className={classes.ListService}>
                    <Typography variant="h6" component="h6" style={{color: "rgba(0, 0, 0, 0.54)"}}>
                    <PlayArrowRoundedIcon style={{ marginLeft: "10px", fontSize: "17px", color: "rgba(0, 0, 0, 0.54)"}}/> List Authentication Services :
                    </Typography>
                    <GitHubLogin
                        className={(dataState.TokenServices && dataState.TokenServices.Github && dataState.TokenServices.Github.length) ? classes.DisableOauthGithub : classes.OauthGithub}
                        clientId="4d2873338bb03f9ec247"
                        scope={"repo"}
                        redirectUri="http://localhost:3000/dashboard/profile"
                        disabled={Boolean(dataState.TokenServices && dataState.TokenServices.Github && dataState.TokenServices.Github.length)}
                        onSuccess={(el) => setOauthGitHub((dataState.TokenServices && dataState.TokenServices.Github && dataState.TokenServices.Github.length) ? undefined : el)}>
                        <img src={GithubIcon} alt="" style={{height: "25px", width: "25px", margin: "10px", marginRight: "15px"}} /> Sign in with GitHub
                    </GitHubLogin>
                    <OAuth2Login
                        className={(dataState.TokenServices && dataState.TokenServices.Imgur && dataState.TokenServices.Imgur.length) ? classes.DisableOauthGithub : classes.OauthGithub}
                        authorizationUrl={`https://api.imgur.com/oauth2/authorize`}
                        responseType="token"
                        clientId="d247b54a5263816"
                        redirectUri="http%3A%2F%2Flocalhost%3A3000%2Fdashboard%2Fprofile"
                        onSuccess={(el) =>  setOauthImgur((dataState.TokenServices && dataState.TokenServices.Imgur && dataState.TokenServices.Imgur.length) ? undefined : el)}>
                            <img src={ImgurIcon} alt="" style={{height: "25px", width: "25px", margin: "10px", marginRight: "15px"}} /> Sign in with Imgur
                    </OAuth2Login>
                    <OAuth2Login
                        className={(dataState.TokenServices && dataState.TokenServices.Twitch && dataState.TokenServices.Twitch.length) ? classes.DisableOauthGithub : classes.OauthGithub}
                        authorizationUrl={`https://id.twitch.tv/oauth2/authorize`}
                        responseType="token"
                        clientId="mw2o23npn444en9kgkdarmkurmpfoa&scope=user:edit+user:read:email"
                        redirectUri="http%3A%2F%2Flocalhost%3A3000%2Fdashboard%2Fprofile"
                        onSuccess={(el) =>  setOauthTwitch((dataState.TokenServices && dataState.TokenServices.Twitch && dataState.TokenServices.Twitch.length) ? undefined : el)}>
                            <img src={TwitchIcon} alt="" style={{height: "25px", width: "25px", margin: "10px", marginRight: "15px"}} /> Sign in with Twitch
                    </OAuth2Login>
                    <GoogleLogin
                        className={(dataState.TokenServices && dataState.TokenServices.Google && dataState.TokenServices.Google.length) ? classes.DisableOauthGoogle : classes.OauthGoogle}
                        clientId="941286274305-8s211plg3f1hnscoqufagurc5sf0gm79.apps.googleusercontent.com"
                        buttonText="Login"
                        cookiePolicy={'single_host_origin'}
                        scope="https://www.googleapis.com/auth/youtube.readonly"
                        onSuccess={(el) => setOauthGoogle((dataState.TokenServices && dataState.TokenServices.Google && dataState.TokenServices.Google.length) ? undefined : el)}>
                        Sign in with Google
                    </GoogleLogin>
                    <MicrosoftLogin
                        className={(dataState.TokenServices && dataState.TokenServices.Microsoft && dataState.TokenServices.Microsoft.length) ? classes.DisableOauthMicrosoft : classes.OauthMicrosoft}
                        clientId="858f7db8-ddb2-4d77-b527-0d565e225ae9"
                        redirectUri="http://localhost:3000/"
                        authCallback={(el) =>  setOauthMicrosoft((dataState.TokenServices && dataState.TokenServices.Microsoft && dataState.TokenServices.Microsoft.length) ? undefined : el)}
                    />
                </div>
            </Grid>
            <img src={carapute} style={{ height: '70px', width: '70px', margin: 'auto' }} alt="" />
            <MySnackBar message={snackbar.message} type={snackbar.type} recall={snackbar.recall} />
        </div>
    );
}

export default DashboardProfile;