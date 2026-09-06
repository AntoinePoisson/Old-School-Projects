import React, { Component } from 'react';
import PropTypes from "prop-types";
import IconButton from '@material-ui/core/IconButton';
import Input from '@material-ui/core/Input';
import InputLabel from '@material-ui/core/InputLabel';
import InputAdornment from '@material-ui/core/InputAdornment';
import FormControl from '@material-ui/core/FormControl';
import Button from '@material-ui/core/Button';
import clsx from 'clsx';
import Visibility from '@material-ui/icons/Visibility';
import VisibilityOff from '@material-ui/icons/VisibilityOff';
import { withStyles } from "@material-ui/core/styles";
import Paper from '@material-ui/core/Paper';
import './mylogin.css'

const styles = theme =>({
    paper: {
        height: 160,
        width: 250,
      },
});

class MyLogin extends Component {
    state = {
        username: '',
        password: '',
        showPassword: false,
    }

    ClickSignIn = (username, password) => {
        if (username !== '' && password !== '') {
            this.props.registering(username, password, true);
        }
    }

    handleChangePassWord = (event) => {
        this.setState({ password: event.target.value });
    };
    
    handleChangeUserName = (event) => {
        this.setState({ username: event.target.value });
    };

     handleClickShowPassword = () => {
        this.setState({ showPassword: !this.state.showPassword });
    };

    render() {
        const { classes } = this.props;
        const { username, password, showPassword } = this.state
        return (
             <div>
                   <img className='bg'
                        component='img'
                        src='https://source.unsplash.com/random/1920x1080'
                        alt=''
                    />
                    <div id="root">
                        <div className='block'>
                            <Paper id='input' className={classes.paper}>
                                <FormControl className={clsx(classes.margin, classes.textField)}>
                                    <InputLabel htmlFor="adornment-username">Username</InputLabel>
                                    <Input
                                        id="adornment-username"
                                        type="text"
                                        value={username}
                                        onChange={this.handleChangeUserName}
                                    />
                                    </FormControl>
                                <FormControl className={clsx(classes.margin, classes.textField)}>
                                    <InputLabel htmlFor="adornment-password">Password</InputLabel>
                                    <Input
                                        id="adornment-password"
                                        type={showPassword ? 'text' : 'password'}
                                        value={password}
                                        onChange={this.handleChangePassWord}
                                        endAdornment={
                                            <InputAdornment position="end">
                                            <IconButton aria-label="Toggle password visibility" onClick={this.handleClickShowPassword}>
                                                {showPassword ? <Visibility /> : <VisibilityOff />}
                                            </IconButton>
                                            </InputAdornment>
                                        }
                                    />
                                </FormControl>
                                <div className="buttonSignIn">
                                <Button variant="contained" color="primary" size="large" fullWidth onClick={() => {this.ClickSignIn(username, password)}}>
                                    Sign In
                                </Button>
                                </div>
                            </Paper>
                        </div>
                    </div>
            </div>
        )
    }
}

MyLogin.propTypes = {
    registering: PropTypes.func.isRequired
}

export default withStyles(styles)(MyLogin);