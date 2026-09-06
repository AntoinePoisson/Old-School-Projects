import React, { useState } from 'react';

import { FormControl, InputLabel, Input, Button, InputAdornment, IconButton } from '@material-ui/core';

import { Visibility, VisibilityOff } from '@material-ui/icons';

import useStyles from '../../../styles/Login';

import MySnackBar from '../../Tools/SnackBar';


const LoginInput = ({isRegisterAndNotLoging, isInput, setInput}) => {

    const classes = useStyles();

    const [showPassword, setShowPassword] = useState(false);

    return (
        <div>
            { (isRegisterAndNotLoging === true) ?
                <form className={classes.form}>
                    <FormControl className={classes.formItem}>
                        <InputLabel htmlFor="adornment-email">Email</InputLabel>
                        <Input
                            className={classes.formItemInput}
                            id="adornment-email"
                            type="text"
                            value={isInput.email}
                            disabled={isInput.clicked}
                            onChange={(event) => setInput({...isInput, email: event.target.value})}
                        />
                    </FormControl>
                    <FormControl className={classes.formItem}>
                        <InputLabel htmlFor="adornment-username">Username</InputLabel>
                        <Input
                            className={classes.formItemInput}
                            id="adornment-username"
                            type="text"
                            value={isInput.username}
                            disabled={isInput.clicked}
                            onChange={(event) => setInput({...isInput, username: event.target.value})}
                        />
                    </FormControl>
                    <FormControl className={classes.formItem}>
                        <InputLabel htmlFor="adornment-password">Password</InputLabel>
                        <Input
                            className={classes.formItemInput}
                            id="adornment-password"
                            type={showPassword ? "text" : "password"}
                            value={isInput.password}
                            disabled={isInput.clicked}
                            onChange={(event) => setInput({...isInput, password: event.target.value})}
                            endAdornment={
                                <InputAdornment position="end">
                                    <IconButton
                                    aria-label="toggle password visibility"
                                    onClick={() => setShowPassword(!showPassword)}
                                    disabled={isInput.clicked}
                                    >
                                        { showPassword ? <Visibility /> : <VisibilityOff /> }
                                    </IconButton>
                                </InputAdornment>
                            }
                        />
                    </FormControl>
                    <Button
                        className={classes.formItemButton}
                        onClick={() => setInput({...isInput, clicked: true})}
                        disabled={((isInput.clicked) || (!isInput.password.length || !isInput.username.length || !isInput.email.length))}
                        variant="contained"
                        color="primary"
                        size="large">
                        Register
                    </Button>
                </form>
                :
                <form className={classes.form}>
                    <FormControl className={classes.formItem}>
                        <InputLabel htmlFor="adornment-email">Email</InputLabel>
                        <Input
                            className={classes.formItemInput}
                            id="adornment-email"
                            type="text"
                            value={isInput.email}
                            disabled={isInput.clicked}
                            onChange={(event) => setInput({...isInput, email: event.target.value})}
                        />
                    </FormControl>
                    <FormControl className={classes.formItem}>
                        <InputLabel htmlFor="adornment-username">Password</InputLabel>
                        <Input
                            className={classes.formItemInput}
                            id="adornment-username"
                            type={showPassword ? "text" : "password"}
                            value={isInput.password}
                            disabled={isInput.clicked}
                            onChange={(event) => setInput({...isInput, password: event.target.value})}
                            endAdornment={
                                <InputAdornment position="end">
                                    <IconButton
                                    aria-label="toggle password visibility"
                                    onClick={() => setShowPassword(!showPassword)}
                                    disabled={isInput.clicked}
                                    >
                                        { showPassword ? <Visibility /> : <VisibilityOff /> }
                                    </IconButton>
                                </InputAdornment>
                            }
                        />
                    </FormControl>
                    <Button
                        className={classes.formItemButton}
                        onClick={() => setInput({...isInput, clicked: true})}
                        disabled={((isInput.clicked) || (!isInput.password.length || !isInput.email.length))}
                        variant="contained"
                        color="primary"
                        size="large">
                        Login
                    </Button>
                </form>
            }
            <MySnackBar message="Welcome on Dashboard Site !" type="info" />
        </div>
    );
};

export default LoginInput;