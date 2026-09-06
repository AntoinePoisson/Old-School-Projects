import React from 'react';

import { Backdrop, Modal, Typography, Grow, Paper, Divider, IconButton } from '@material-ui/core';
import CloseIcon from '@material-ui/icons/Close';
import useStyles from '../../styles/ModalImgurImage';


const ModalImgurImage = ({open, setClose}) => {

    const classes = useStyles();


    return (
        <Modal closeAfterTransition
            className={classes.modal}
            aria-labelledby="transition-modal-title"
            aria-describedby="transition-modal-description"
            open={open.open}
            BackdropComponent={Backdrop}
            onClose={setClose}
        >
            <Grow in={open.open} {...({ timeout: 500 })}>
                <Paper className={classes.Paper}>
                    <div className={classes.Bar}>
                        <Typography variant="h4" className={classes.Title}>
                            { open.open ? open.data.title : "" }
                        </Typography>
                        <IconButton size="medium" onClick={setClose} style={{color: "black"}}>
                            <CloseIcon />
                        </IconButton>
                    </div>
                    <Divider className={classes.Divider} />
                        { open.open ?
                            <div className={classes.Body}>
                                <img src={open.data.type ? open.data.link : open.data.images[0].link} alt={""} style={{maxWidth: "75vw", display: "flex", marginLeft: "auto", marginRight: "auto"}} />
                            </div>
                            :
                            <div/>
                        }
                </Paper>
            </Grow>
        </Modal>
    );
};

export default ModalImgurImage;