import React, { Component } from 'react';
import PropTypes from 'prop-types'
import { Grid, Typography } from "@material-ui/core";
import Card from "@material-ui/core/Card";
import CardContent from "@material-ui/core/CardContent";
import CardMedia from "@material-ui/core/CardMedia";
import { withStyles } from "@material-ui/core/styles";


const styles = theme =>({
    card: {
        width: 405,
        minHeight: 315,
    },
    media: {
        display: 'block',
        maxHeight: 210,
    },
    title: {
        fontSize: 23,
    },
    text: {
        fontSize: 12,
    },
});

class DisplayData extends Component {
    display(classes) {
        if (this.props.data != null) {
            return (
                this.props.data.map((element, index) => {
                    return (
                        <Grid item key={index}>
                            <Card className={classes.card}>
                                <CardMedia
                                    className={classes.media}
                                    component="img"
                                    src={element.url}
                                    alt=""
                                />
                                <CardContent>
                                    <Typography
                                        gutterBottom
                                        className={classes.title}
                                        variant="h5"
                                        component="h2">
                                            { element.title }
                                    </Typography>
                                    <Typography
                                        className={classes.text}
                                        variant="body2"
                                        color="textSecondary"
                                        component="p">
                                            <a
                                                href={element.url}>
                                                {element.url}
                                            </a>
                                    </Typography>
                                </CardContent>
                            </Card>
                            <br/>
                        </Grid>
                    )
                })
            )
        }
    }

    render() {
        const { classes } = this.props;
        return (
            <div style={{ marginTop: 20, padding: 30 }}>
                <Grid
                    container
                    direction="row"
                    justify="space-evenly"
                    alignItems="center">
                        { this.display(classes) }
                </Grid>
            </div>
        )
    }
}

DisplayData.propTypes = {
    data: PropTypes.array.isRequired
}

export default withStyles(styles)(DisplayData);