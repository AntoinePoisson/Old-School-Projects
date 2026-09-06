import React, { useState, useEffect, useContext } from 'react';

import CircularProgress from '@material-ui/core/CircularProgress';
import { Paper, Button, Typography, Divider, Grid, Menu, MenuItem, Grow } from '@material-ui/core';

import { Redirect } from 'react-router-dom';

import LoginInput from './components/Displays/LoginPage/MainComponent'

import useStyles from './styles/Login';
import ModalCodeConfirmation from './components/Modals/CodeConfirmation';
import MySnackBar from './components/Tools/SnackBar';
import GoogleLogin from 'react-google-login';
import DataContext from './contexts/dataContext';


const Login = () => {

    const classes = useStyles();

    const [isLog, setLog] = useState(false);
    const [snackbar, setSnackbar] = useState({message: "", type: "", recall: 0})
    const [isRegisterAndNotLoging, setRegisterAndNotLoging] = useState(false);
    const [isOpenModal, setOpenModal] = useState(false);
    const [isInput, setInput] = useState({username: "", password: "", email: "", clicked: false, codeConfirmation: ""});
    const [google, setGoogle] = useState(undefined);
    const [isLoading, setLoading] = useState(false);
    const [anchorEl, setAnchorEl] = useState(null);
    const [dataState, ] = useContext(DataContext);

    useEffect(() => {
        if (document.cookie.split('; ').find(row => row.startsWith('tokenDashboardEpi')) !== undefined
            && document.cookie.split('; ').find(row => row.startsWith('tokenDashboardEpi')).split('=')[1] !== undefined
            && document.cookie.split('; ').find(row => row.startsWith('tokenDashboardEpi')).split('=')[1].length !== 0) {
            setSnackbar({ message: "Always Registing", type: "success", recall: snackbar.recall + 1 });
            setLog(true);
            return;
        }
        if (isInput.clicked === false)
            return;
        if (isRegisterAndNotLoging) {
            if (isInput.codeConfirmation === "" && isOpenModal === false) {
                const myInit = {
                    method: "POST",
                    headers: new Headers({ "Content-Type": "application/json" }),
                    mode: "cors",
                    body: JSON.stringify({username: isInput.username, email: isInput.email, password: isInput.password}),
                    cache: "default"
                };
                fetch(`http://localhost:8080/register`, myInit)
                    .then(async res => {
                        const result = await res.json()
                        if (result.error) {
                            setSnackbar({ message: result.error.description, type: "error", recall: snackbar.recall + 1 });
                            setInput({...isInput, clicked: false })
                        } else {
                            setSnackbar({ message: "Registing Success", type: "success", recall: snackbar.recall + 1 });
                            setLoading(true);
                            setOpenModal(true);
                            setInput({...isInput, codeConfirmation: ""});
                        }
                    })
                    .catch((error) => {
                        setSnackbar({ message: "Wrong information", type: "error", recall: snackbar.recall + 1 });
                        setInput({...isInput, clicked: false })
                    })
                return;
            } else if (isOpenModal === false) {
                const myInit = {
                    method: "POST",
                    headers: new Headers({ "Content-Type": "application/json" }),
                    mode: "cors",
                    body: JSON.stringify({ code: isInput.codeConfirmation, email: isInput.email }),
                    cache: "default"
                };
                fetch(`http://localhost:8080/check-code`, myInit)
                    .then(async res => {
                        const result = await res.json()
                        if (result.error) {
                            setOpenModal(true);
                            setSnackbar({ message: "Wrong Code", type: "error", recall: snackbar.recall + 1 });
                            setInput({...isInput, codeConfirmation: ""});
                        } else {
                            setInput({...isInput, codeConfirmation: ""});
                            setSnackbar({ message: "Registing Complete !", type: "success", recall: snackbar.recall + 1 });
                            setOpenModal(false);
                            document.cookie = `tokenDashboardEpi=${result.result.token}; expires= Thu, 20 Aug 2045 20:20:20 UTC; SameSite=None; Secure`
                            setLog(true);
                        }
                    })
                    .catch((error) => {
                        setOpenModal(true);
                        setSnackbar({ message: "Wrong Code", type: "error", recall: snackbar.recall + 1 });
                        setInput({...isInput, codeConfirmation: ""});
                    })
                return;
            }
        } else {
            const myInit = {
                method: "POST",
                headers: new Headers({ "Content-Type": "application/json" }),
                mode: "cors",
                body: JSON.stringify({ email: isInput.email, password: isInput.password }),
                cache: "default"
            };
            fetch(`http://localhost:8080/login`, myInit)
                .then(async res => {
                    const result = await res.json()
                    if (result.error) {
                        setSnackbar({ message: result.error.description, type: "error", recall: snackbar.recall + 1 });
                        setInput({...isInput, clicked: false});
                    } else {
                        setSnackbar({ message: "Login Complete !", type: "success", recall: snackbar.recall + 1 });
                        document.cookie = `tokenDashboardEpi=${result.result.token}; expires= Thu, 20 Aug 2045 20:20:20 UTC; SameSite=None; Secure`
                        setLog(true);
                    }
                })
                .catch((error) => {
                    setSnackbar({ message: "Wrong Information", type: "error", recall: snackbar.recall + 1 });
                    setInput({...isInput, clicked: false});
                })
        }
    // eslint-disable-next-line react-hooks/exhaustive-deps
    }, [isInput.clicked, isOpenModal]);

    useEffect(() => {
        if (!google)
            return;
        const myInit = {
            method: "POST",
            headers: new Headers({ "Content-Type": "application/json" }),
            mode: "cors",
            body: JSON.stringify({username: google.profileObj.givenName, email: google.profileObj.email, password: " ", code: true}),
            cache: "default"
        };
        fetch(`http://localhost:8080/register`, myInit)
            .then(async res => {
                const result = await res.json()
                if (result.error) {
                    setSnackbar({ message: result.error.description, type: "error", recall: snackbar.recall + 1 });
                } else {
                    const myInit_ = {
                        method: "POST",
                        headers: new Headers({ "Content-Type": "application/json" }),
                        mode: "cors",
                        body: JSON.stringify({token: result.result.token}),
                        cache: "default"
                    };
                    fetch(`http://localhost:8080/token/get`, myInit_)
                        .then(async (r) => {
                            const re = await r.json();
                            if (re.error) {
                                setSnackbar({ message: "Failure Login with Google", type: "error", recall: snackbar.recall + 1 });
                            } else {
                                const myInit_ = {
                                    method: "POST",
                                    headers: new Headers({ "Content-Type": "application/json" }),
                                    mode: "cors",
                                    body: JSON.stringify({token: result.result.token, tokens: JSON.stringify({...dataState.TokenServices, Google: google.accessToken})}),
                                    cache: "default"
                                };
                                fetch(`http://localhost:8080/token/save`, myInit_)
                                    .then(async (res) => {
                                        setSnackbar({ message: "Registing Complete !", type: "success", recall: snackbar.recall + 1 });
                                        document.cookie = `tokenDashboardEpi=${result.result.token}; expires= Thu, 20 Aug 2045 20:20:20 UTC; SameSite=None; Secure`
                                        setLog(true);
                                    })
                                    .catch((error) => {
                                        setSnackbar({ message: "Failure Login with Google", type: "error", recall: snackbar.recall + 1 });
                                    });
                            }
                        })
                        .catch((error) => {
                            setSnackbar({ message: "Failure Login with Google", type: "error", recall: snackbar.recall + 1 });
                        });
                }
            })
            .catch((error) => {
                setSnackbar({ message: "Failure Login with Google", type: "error", recall: snackbar.recall + 1 });
            })
        // eslint-disable-next-line react-hooks/exhaustive-deps
    }, [google]);

    if (isLog === true) return ( <Redirect to="/dashboard" /> );

    return (
        <div className={classes.root}>
            <Paper className={classes.block}>
                <Typography className={classes.title} variant="h4" component="h5">
                    Dashboard
                </Typography>
                <Grid container direction="row" justify="center" alignItems="center" style={{ flexWrap: "unset" }}>
                    <Grid item xs={4}>
                        <Button className={classes.tierButton} disabled={isLoading || isInput.clicked} variant="outlined" onClick={(event) => setAnchorEl(event.currentTarget)}>Other</Button>
                        <Menu
                            id="simple-menu"
                            anchorEl={anchorEl}
                            keepMounted
                            anchorOrigin={{
                                vertical: 'top',
                                horizontal: 'left',
                            }}
                            transformOrigin={{
                                vertical: 'center',
                                horizontal: 'right',
                            }}
                            open={Boolean(anchorEl)}
                            onClose={() => setAnchorEl(null)}
                            TransitionComponent={Grow}
                        >
                            <MenuItem onClick={() => {}}>
                                <GoogleLogin
                                    className={classes.OauthGoogle}
                                    clientId="941286274305-8s211plg3f1hnscoqufagurc5sf0gm79.apps.googleusercontent.com"
                                    buttonText="Login"
                                    cookiePolicy={'single_host_origin'}
                                    scope="https://www.googleapis.com/auth/youtube.readonly"
                                    onSuccess={(el) => setGoogle(el)}
                                    onFailure={(el) => console.log(el)}>
                                    Login with Google
                                </GoogleLogin>
                            </MenuItem>
                        </Menu>
                    </Grid>
                    <Grid item xs={8}>
                        <Button
                            className={classes.switcher}
                            variant="outlined"
                            disabled={isLoading || isInput.clicked}
                            onClick={() => setRegisterAndNotLoging(!isRegisterAndNotLoging)}>
                            { (isRegisterAndNotLoging === true) ? "Login" : "Register" }
                        </Button>
                    </Grid>
                </Grid>
                <Divider className={classes.divider} />
                { !isLoading ?
                    <LoginInput
                        isRegisterAndNotLoging={isRegisterAndNotLoging}
                        isInput={isInput}
                        setInput={(element) => setInput(element)} />
                    :
                    <CircularProgress className={classes.spinner} />
                }
            </Paper>
            <MySnackBar message={snackbar.message} type={snackbar.type} recall={snackbar.recall} />
            <ModalCodeConfirmation
                open={isOpenModal}
                setOpen={(value) => setOpenModal(value)}
                isInput={isInput}
                setInput={(elements) => setInput(elements)}
                code={"123456"} />
        </div>
    );
};

export default Login;