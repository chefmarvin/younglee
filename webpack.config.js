var webpack = require('webpack');

module.exports = {
    entry: {
        "younglee": './src/younglee.ts',
        "younglee-en": './src/younglee-en.ts',
        "younglee-ch": './src/younglee-ch.ts'
    },
    output: {
        filename: '[name]',
        path: __dirname + "/bin"
    },
    resolve: {
        extensions: ['.ts', '.js', '.json']
    },
    target: 'node',
    module: {
        rules: [
            {
                test: /\.ts$/,
                use: [{
                    loader: 'awesome-typescript-loader'
                }]
            },
            {
                test: /\.node$/,
                use: [{
                    loader: 'file-loader'
                }]
            }
        ]
    },
    plugins: [
        new webpack.BannerPlugin({
            banner: '#!/usr/bin/env node',
            raw: true
        }),
        new webpack.optimize.ModuleConcatenationPlugin()
    ]
};
