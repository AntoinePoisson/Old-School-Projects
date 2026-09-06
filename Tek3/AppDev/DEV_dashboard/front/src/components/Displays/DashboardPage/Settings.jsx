import React, { useContext, useEffect, useState } from 'react';
import { Button, Grow, Typography } from '@material-ui/core';

import PlayArrowRoundedIcon from '@material-ui/icons/PlayArrowRounded';
import ContentEditable from "react-contenteditable";

import { BallTriangle } from '@agney/react-loading';

import useStyles from '../../../styles/DashboardSettings';
import MySnackBar from '../../Tools/SnackBar';
import DataContext from '../../../contexts/dataContext';


const DashboardSettings = () => {

    const classes = useStyles();

    const [text, setText] = useState("");
    const [loading, setLoading] = useState(true);
    const [change, setChange] = useState(undefined);
    const [snackbar, setSnackbar] = useState({message: "", type: "", recall: 0})
    const [, dataDispatch] = useContext(DataContext);

    useEffect(() => {
        const myInit_ = {
            method: "GET",
            headers: new Headers({ "Content-Type": "application/json" }),
            mode: "cors",
            cache: "default"
        };
        fetch(`http://localhost:8080/about/get`, myInit_)
            .then(async (res) => {
                const result = await res.json();
                if (result.error) {
                    setSnackbar({ message: "Failure get Config", type: "error", recall: snackbar.recall + 1 });
                } else {
                    setText(`${JSON.stringify(result.result, null, 4).replace(/ /g, '&nbsp;').replace(/(\n)/g, '<br>')}`);
                    dataDispatch({ type: "SET_ABOUT_JSON", About: result.result });
                    setLoading(false);
                }
            })
            .catch((error) => {
                setSnackbar({ message: "Failure get Config", type: "error", recall: snackbar.recall + 1 });
            });
    // eslint-disable-next-line react-hooks/exhaustive-deps
    }, []);

    useEffect(() => {
        if (change === undefined)
            return;
        try {
            JSON.parse(text.replace(/&nbsp;/g, '').replace(/(<br>)/g, '\n'));
        } catch(error) {
            setSnackbar({ message: "Wrong format JSON", type: "error", recall: snackbar.recall + 1 });
            setChange(undefined)
            return;
        }
        const myInit_ = {
            method: "POST",
            headers: new Headers({ "Content-Type": "application/json" }),
            mode: "cors",
            body: JSON.stringify({dashboard: text.replace(/&nbsp;/g, ' ').replace(/(<br>)/g, '\n') }),
            cache: "default"
        };
        fetch(`http://localhost:8080/about/save`, myInit_)
            .then(async (res) => {
                const result = await res.json();
                if (result.error) {
                    setSnackbar({ message: "Failure get Config", type: "error", recall: snackbar.recall + 1 });
                } else {
                    setSnackbar({ message: "Saving Config", type: "success", recall: snackbar.recall + 1 });
                    dataDispatch({ type: "SET_ABOUT_JSON", About: JSON.parse(text.replace(/&nbsp;/g, ' ').replace(/(<br>)/g, '\n')) });
                }
            })
            .catch((error) => {
                setSnackbar({ message: "Failure get Config", type: "error", recall: snackbar.recall + 1 });
            });
        setChange(undefined)
    // eslint-disable-next-line react-hooks/exhaustive-deps
    }, [change]);

    if (loading) {
        return (
            <div className={classes.root}>
            <Typography
                className={classes.title}
                variant="h4"
                component="h4">
                <PlayArrowRoundedIcon style={{ marginLeft: "20px", fontSize: "26px" }}/> About Configuration
            </Typography>
            <Grow in={true} {...({ timeout: 1000 })}>
                <div style={{display: "flex", height: "100%", position: "relative", justifyContent: "center"}}>
                    <BallTriangle width={300} style={{color: "white"}} />
                </div>
            </Grow>
        </div>
        );
    }


    return (
        <div className={classes.root}>
            <Typography
                className={classes.title}
                variant="h4"
                component="h4">
                <PlayArrowRoundedIcon style={{ marginLeft: "20px", fontSize: "26px" }}/> About Configuration
            </Typography>
            <ContentEditable
                className={classes.text}
                html={text}
                onChange={(event) => setText(event.target.value)}
                />
            <div style={{display: "flex", justifyContent: "center"}}>
                <Button
                    className={classes.button}
                    onClick={() => setChange(true)}
                    variant="contained"
                    color="primary"
                    size="large">
                    Valide
                </Button>
            </div>
            <MySnackBar message={snackbar.message} type={snackbar.type} recall={snackbar.recall} />
        </div>
    );
};

export default DashboardSettings;