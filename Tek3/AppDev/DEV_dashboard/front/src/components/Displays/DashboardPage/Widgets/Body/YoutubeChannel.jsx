import React from 'react';

import { Avatar, Grid, Typography, Button } from '@material-ui/core';


const BodyYoutubeChannel = ({data}) => {

    return (
        <Grid>
            <Grid container direction='row'>
                <Avatar src={data.items[0].snippet.thumbnails.default.url } style={{ height: '70px', width: '70px' }} alt='avatar'/>
                <Typography style={{ marginLeft: '30px', marginTop: '20px'}} variant='h4' >{ data.items[0].snippet.title }</Typography>
            </Grid>
            <Grid container direction='row' style={{ marginTop: '50px'}}>
                    <Grid item xs={4} style={{display: 'flex', flexDirection: 'column'}}>
                            <Typography align='center'>View count</Typography>
                            <Typography align='center'>{data.items[0].statistics.viewCount}</Typography>
                    </Grid>
                    <Grid item xs={4} style={{display: 'flex', flexDirection: 'column'}}>
                            <Typography align='center'>Subscriber count</Typography>
                            <Typography align='center'>{data.items[0].statistics.subscriberCount}</Typography>
                    </Grid>
                    <Grid item xs={4} style={{display: 'flex', flexDirection: 'column'}}>
                            <Typography align='center'>Video count</Typography>
                            <Typography align='center'>{data.items[0].statistics.videoCount}</Typography>
                    </Grid>
            </Grid>
            <Grid container direction='row' justify='center' style={{ marginTop: '10px'}}>
                <Button style={{backgroundColor: 'red'}} href={'https://www.youtube.com/channel/' + data.items[0].id} target="_blank">Channel</Button>
            </Grid>
        </Grid>
    );
};

export default BodyYoutubeChannel;