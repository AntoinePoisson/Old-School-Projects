import React from 'react';
import { Grid, List, Typography, Divider } from '@material-ui/core';


const BodyGithubIssue = ({data}) => {

    return (
        <Grid>
            <List>
                { data.map((elem, index) => {
                    return (
                        <Grid>
                            <Typography>{elem.title}</Typography>
                            <Divider/>
                        </Grid>
                    )
                })
                }
            </List>
        </Grid>
    );
};

export default BodyGithubIssue;
