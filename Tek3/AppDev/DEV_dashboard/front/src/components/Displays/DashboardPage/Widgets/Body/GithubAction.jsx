import React from 'react';
import { Grid, Typography, Divider } from '@material-ui/core';
import CancelIcon from '@material-ui/icons/Cancel';
import CheckCircleIcon from '@material-ui/icons/CheckCircle';

const BodyGithubAction = ({data}) => {

    const Title = () => {
        return (
            <Grid>
                <Grid container style={{ display: 'flex', justifyContent: 'space-around'}}>
                    <Grid item xs={4}>
                        <Typography align='center'>Branch</Typography>
                    </Grid>
                    <Grid item xs={4}>
                        <Typography align='center'>Action</Typography>
                    </Grid>
                    <Grid item xs={4}>
                        <Typography align='center'>Status</Typography>
                    </Grid>
                </Grid>
                <Divider/>
            </Grid>
        )
    };

    return (
        <Grid>
            <Title/>
            { data.map((elem, index) => {
                    return (
                        <Grid key={index.toString()}>
                            <Grid container style={{ display: 'flex', justifyContent: 'space-around'}}>
                                <Grid item xs={4}>
                                    <Typography align='center'>{elem.head_branch}</Typography>
                                </Grid>
                                <Grid item xs={4}>
                                    <Typography align='center'>{elem.name}</Typography>
                                </Grid>
                                <Grid item xs={4} >
                                    { (elem.conclusion === "success") ?
                                            <CheckCircleIcon style={{ margin: 'auto', display: 'flex', color: 'green'}}/>
                                        :
                                            <CancelIcon style={{ margin: 'auto', display: 'flex', color: 'red'}}/>
                                    }
                                </Grid>

                            </Grid>
                            <Divider/>
                        </Grid>
                    )
                })
            }
        </Grid>
    );
};

export default BodyGithubAction;
