import React from 'react';
import { makeStyles } from '@material-ui/core/styles';
import { Modal, Paper, Fade, Grid, IconButton } from '@material-ui/core';
import HighlightOffIcon from '@material-ui/icons/HighlightOff';


const useStyles = makeStyles(theme => ({
    container: {
        display: 'flex',
        flexDirection: "column",
        alignItems: "center",
        background: "#d8d8d8cc",
        position: "absolute",
        minWidth: "70vw",
        maxWidth: "95vw",
        minHeight: "79vh",
        maxHeight: "90vh",
        paddingTop: "10px",
        paddingBottom: "10px",
        margin: "20px 0"
    },
    modalCenter: {
        display: 'flex',
        justifyContent: 'center',
        alignItems: 'center'
    },
  }));

  const TOIMG = (link) => {
    window.open(link);
  };

export default function IsModale({isOpened, handleClose}) {
    const classes = useStyles();

  return (
    <div>
        <Modal
            aria-labelledby="simple-modal-title"
            aria-describedby="simple-modal-description"
            open={isOpened.state}
            onClose={handleClose}
            className={classes.modalCenter}
        >
            <Fade in={isOpened.state}>
                <Paper className={classes.container}>
                    <Grid item style={{width: "90%", minHeight: "55px", maxHeight: "90px"}}>
                    <div>
                        <Grid container justify="space-between" direction="row">
                            <Grid item xs={2}>
                            </Grid>
                            <Grid item xs={8} style={{textAlign: "center"}}>
                                {/* <Typography> */}
                                <p  style={{fontSize: '1.5rem'}}> { isOpened.data.title } </p>
                            </Grid>
                            <Grid item xs={2} style={{display: "flex"}}>
                                <IconButton onClick={() => handleClose()}
                                    size="medium"
                                    style={{marginLeft: 'auto', marginBottom: 'auto', marginTop: 'auto', color: 'black'}}
                                >
                                    <HighlightOffIcon style={{fontSize: '2.0rem'}}/>
                                </IconButton>
                            </Grid>
                        </Grid>
                        </div>
                    </Grid>
                    <Grid item>
                        <img src={isOpened.data.url} alt="" onClick={() => TOIMG(isOpened.data.url)} style={{cursor: 'pointer', height: '600px'}}/>
                    </Grid>
                    <Grid item xs={12} style={{width: '100%', height: '100%', textAlign: 'center', overflowY: 'auto'}}>
                        <p> { isOpened.data.explanation } </p>
                    </Grid>
                </Paper>
            </Fade>
        </Modal>
    </div>
  );
}