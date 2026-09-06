import React, { useState } from 'react';

import { Redirect } from 'react-router-dom';

import { Button, Paper, Typography } from '@material-ui/core';

import ArrowBackIosIcon from '@material-ui/icons/ArrowBackIos';

import useStyles from './styles/NotFoundPage';


const NotFoundPage = () => {

    const classes = useStyles();

    const [isLeave, setLeave] = useState(false);


    if (isLeave) return ( <Redirect exact to='/login' /> );


    return (
        <div className={classes.root}>
            <Paper className={classes.paper}>
                <Typography variant="h5" gutterBottom align="center">
                    Erreur 404: Page Introuvable
                </Typography>
                <Typography variant="body1" gutterBottom align="center">
                    l'URL saisies est inconnu
                </Typography>
                <div className={classes.button}>
                    <Button variant="contained" color="primary" fullWidth onClick={() => setLeave(true)}>
                        <ArrowBackIosIcon />
                        Retour au Site
                    </Button>
                </div>
            </Paper>
        </div>
    );
};

export default NotFoundPage;