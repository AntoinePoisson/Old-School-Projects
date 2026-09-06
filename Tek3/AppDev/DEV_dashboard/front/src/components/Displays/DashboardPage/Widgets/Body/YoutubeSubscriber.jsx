import * as React from 'react';

import { Avatar, Grid, Typography, Divider } from '@material-ui/core';
import Moment from 'react-moment';

const BodyYoutubeSubscriber = ({data}) => {

    return (
        <Grid>
            <Grid container key={"index.toString()"}>
                        <Grid container direction='row'>
                            <Grid item xs={8} container direction='row'>
                                <Typography variant='subtitle1' style={{ marginTop: '5px', marginLeft: '10px'}}>Name</Typography>
                            </Grid>
                            <Grid item xs={4} container direction='row' alignItems='center'>
                                <Typography variant='subtitle1' style={{ marginTop: '5px', marginLeft: '10px'}}>Since</Typography>
                            </Grid>
                        </Grid>
                        <Divider/>
                    </Grid>
            { data.items.map((elem, index) => {
                console.log(elem)
                return (
                    <Grid container key={index.toString()}>
                        <Grid container direction='row'>
                            <Grid item xs={8} container direction='row'>
                                <Avatar src={elem.subscriberSnippet.thumbnails.default.url}/>
                                <Typography variant='subtitle1' style={{ marginTop: '5px', marginLeft: '10px'}}>{elem.subscriberSnippet.title}</Typography>
                            </Grid>
                            { elem.snippet ?
                            <Grid item xs={4} container direction='row' alignItems='center'>
                                <Moment date={elem.snippet.publishedAt} format="YYYY/MM/DD"/>
                            </Grid>
                            :
                            <div/>
                            }
                        </Grid>
                        <Divider/>
                    </Grid>
                )
            })
            }
        </Grid>
    );
};

export default BodyYoutubeSubscriber;