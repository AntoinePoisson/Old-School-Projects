import React from 'react';

import { Backdrop, Modal, Typography, Grow, Paper, Divider, IconButton, Button, TextField } from '@material-ui/core';
import CloseIcon from '@material-ui/icons/Close';
import useStyles from '../../styles/ModalSettingsTemplate';
import { useState } from 'react';


const ModalSettingsMeteo = ({addElement, setData}) => {

    const classes = useStyles();

    const [city, setCity] = useState("Paris");
    const save = () => {
        setData({...addElement, data: {
            city: city,
            title: "Meteo",
            type: "Meteo",
            description: "METEOOOOOOOOOOOOOOOOOO",
            size: 6,
        }})
    };

    return (
        <Modal closeAfterTransition
            className={classes.modal}
            aria-labelledby="transition-modal-title"
            aria-describedby="transition-modal-description"
            open={true}
            BackdropComponent={Backdrop}
            onClose={() => setData({ type: "", clicked: false, data: {} })}
        >
            <Grow in={true} {...({ timeout: 500 })}>
                <Paper className={classes.Paper}>
                    <div className={classes.Bar}>
                        <Typography variant="h4" className={classes.Title}>
                            Settings
                        </Typography>
                        <IconButton size="medium" onClick={() => setData({ type: "", clicked: false, data: {} })} style={{color: "black"}}>
                            <CloseIcon />
                        </IconButton>
                    </div>
                    <Divider className={classes.Divider} />
                    <div className={classes.Body}>
                        <div className={classes.ItemInput}>
                            <TextField id="standard-basic" label="City" value={ city } onChange={ (event) => {
                                setCity(event.target.value)
                            }}/>
                        </div>
                        <div className={classes.ItemInput} style={{marginTop: "35px", display: "grid"}}>
                            <Button
                                variant="contained"
                                color="primary"
                                onClick={ save }>
                                Valide
                            </Button>
                        </div>
                    </div>
                </Paper>
            </Grow>
        </Modal>
    );
};

export default ModalSettingsMeteo;