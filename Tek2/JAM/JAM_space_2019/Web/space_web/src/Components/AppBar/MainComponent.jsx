import React from "react";
import NASA from "../../resources/nasa.png";
import SITE from "../../resources/site.png";
import AppBar from "@material-ui/core/AppBar";
import { makeStyles } from "@material-ui/core/styles";
import Toolbar from "@material-ui/core/Toolbar";
import Paper from "@material-ui/core/Paper";
import IconButton from "@material-ui/core/IconButton";
import CustomizedSearch from "../searchbar"
import { Button, Grid, Divider } from "@material-ui/core";

const useStyles = makeStyles(theme => ({
  root: {
    flexGrow: 1
  },
  paperRoot: {
    width: "300px",
    marginLeft: "70px"
  },
  IconNasa: {
    paddingTop: '3px',
    '& .MuiIconButton-root': {
      padding: "0px"
    }
  },
  ButtonNasa: {
    //marginLeft: "100px",
    color: "#FFFFFF"
  },
  menuButton: {
    marginRight: theme.spacing(2),
    color: "white"
  },
  title: {
    flexGrow: 1,
    color: "white"
  },
  bar:{
    borderRadius: "15px"
  },
  search: {
    position: "relative",
    // borderRadius: theme.shape.borderRadius,
    // backgroundColor: fade(theme.palette.common.white, 0.15),
    // "&:hover": {
    //   backgroundColor: fade(theme.palette.common.white, 0.25)
    // },
    // marginRight: theme.spacing(2),
    // marginLeft: 0,
    // width: "100%",
    // [theme.breakpoints.up("sm")]: {
    //   marginLeft: theme.spacing(3),
    width: "400px"
  }
}));

// const getNames = () => {
//   Test.map() =>
//   <>
// }

const TOSPACE = () => {
  window.open("https://apod.nasa.gov/apod/astropix.html");
};


export default function ButtonAppBar() {
  const classes = useStyles();

  return (
  <>
    <div className={classes.root}>
      <AppBar
        position="static"
        style={{ backgroundColor: "#602670", color: "white", boxShadow: "0px 13px 6px -5px #363636e6", borderRadius: '30px' }}
      >
        <Toolbar>
          <Grid container style={{display: 'flex'}}>
            <Grid item xs={1} style={{marginRight: 'auto', paddingTop: '5px', paddingBottom: '5px'}}>
              <img alt="" src={SITE} style={{width: '185px', height: '58px'}}/>
            </Grid>
            <Grid item style={{paddingLeft: '0px', display: 'flex', paddingRight: '60px'}}>
            <Divider orientation="vertical" style={{
              // border: 'none',
              height: '50px',
              margin: 'auto',
              // flexShrink: '0',
              backgroundColor: 'rgb(255, 255, 255)',
              width: '1px'
            }}/>
            </Grid>
            <Grid item xs={6} className={classes.IconNasa}>
              <IconButton
                type="submit"
                className={classes.iconButton}
                aria-label="search"
              />
              <Button
                type="submit"
                className={classes.ButtonNasa}
                aria-label="search"
                onClick={() => TOSPACE()}
                color="primary"
              >
                <img alt="" src={NASA} width="73px" className={classes.IconNasa} />
              </Button>
            </Grid>
            <Grid item xs={3} style={{margin: 'auto'}}>
              <Paper component="form" className={classes.paperRoot}>
                <CustomizedSearch/>
              </Paper>
            </Grid>
          </Grid>
        </Toolbar>
      </AppBar>
    </div>
    </>
  );
}
